#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>


using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64


#define MAXN 400005
#define INF 0x7fffffff

int n,m,num_edges,colorr[MAXN],mn,first_edge[MAXN],to[MAXN<<1],nxt[MAXN<<1];
int vall[MAXN<<1],ans,k,vis[MAXN],par[MAXN],dep[MAXN],sz[MAXN],numm[MAXN];
int locall[MAXN],globall[MAXN];


void add_edge(int u,int v,int costt)
{
    to[num_edges]=v;
    vall[num_edges]=costt;
    nxt[num_edges]=first_edge[u];
    first_edge[u]=num_edges++;
}

bool cmp(int x,int y)
{
    return dep[to[x]]<dep[to[y]];
}

int dfs_size(int u,int p)
{
    par[u]=p;
    sz[u]=1;

    for(int i=first_edge[u];~i;i=nxt[i])
    {
        if(to[i]==p || vis[to[i]])
        {
            continue;
        }

        sz[u]+=dfs_size(to[i],u);
    }

    //printf("DFSSIZE\t%d\t%d\t%d\n",u,p,sz[u]);

    return sz[u];
}

void dfs_root(int u,int summ,int &root)
{

    int mx=summ-sz[u];

    for(int i=first_edge[u];~i;i=nxt[i])
    {
        int v=to[i];
        if(v==par[u] || vis[v])
        {
            continue;
        }

        dfs_root(v,summ,root);
        mx=max(mx,sz[v]);
    }

    if(mx<mn)
    {
        mn=mx;
        root=u;
    }

    //printf("DFSROOT\t%d\t%d\t%d\t%d\t%d\n",u,summ,root,mx,mn);
}


int dfs_depth(int u,int p)
{
    dep[u]=colorr[u];
    int mx=0;

    for(int i=first_edge[u];~i;i=nxt[i])
    {
        if(vis[to[i]] || to[i]==p)
        {
            continue;
        }

        mx=max(mx,dfs_depth(to[i],u));
    }

    dep[u]+=mx;

    return dep[u];
}

void dfs_ct(int u,int p,int score,int ct)
{
    locall[ct]=max(locall[ct],score);

    for(int i=first_edge[u];~i;i=nxt[i])
    {
        if(to[i]==p || vis[to[i]])
        {
            continue;
        }

        dfs_ct(to[i],u,score+vall[i],ct+colorr[to[i]]);
    }
}



void solve(int u)
{
    //printf("SOLVE\t%d\n",u);
    int summ=dfs_size(u,-1);
    int topp;
    mn=INF;
    int root;

    dfs_root(u,summ,root);
    //printf("Root\t%d\n",root);
    vis[root]=1;


    for(int i=first_edge[root];~i;i=nxt[i])
    {
        if(to[i]!=root && !vis[to[i]])
        {
            solve(to[i]);
        }
    }

    topp=0;

    for(int i=first_edge[root];~i;i=nxt[i])
    {
        if(to[i]==root || vis[to[i]])
        {
            continue;
        }

        dfs_depth(to[i],root);
        numm[topp++]=i;
    }

    sort(numm,numm+topp,cmp);

    for(int i=0;i<dep[to[numm[topp-1]]];++i)
    {
        globall[i]=-INF;
    }

    for(int i=0;i<topp;++i)
    {
        int v=to[numm[i]];
        int ct=dep[v];
        int score=vall[numm[i]];

        for(int j=0;j<=ct;++j)
        {
            locall[j]=-INF;
        }

        dfs_ct(v,root,score,colorr[v]);

        if(i)
        {
            for(int j=0;j<=k-colorr[root] && j<=ct;++j)
            {
                int r=min(dep[to[numm[i-1]]],k-colorr[root]-j);

                if(globall[r]==-INF || locall[j]==-INF)
                {
                    continue;
                }

                ans=max(ans,globall[r]+locall[j]);
            }
        }

        for(int j=0;j<=ct;++j)
        {
            globall[j]=max(globall[j],locall[j]);

            if(j)
            {
                globall[j]=max(globall[j],globall[j-1]);
            }

            if(j+colorr[root]<=k)
            {
                ans=max(ans,globall[j]);
            }
        }
    }


    vis[root]=0;
}


int main()
{
    freopen("Text/FTOUR2.txt","r",stdin);

    scanf("%d%d%d",&n,&k,&m);
    //printf("%d\t%d\t%d\n",n,k,m);
    int x,y,z,ti;

    num_edges=0;

    MSET(colorr,0);
    MSET(vis,0);
    MSET(first_edge,-1);

    for(int i=1;i<=m;++i)
    {
        scanf("%d",&ti);
        //printf("%d\n",ti);
        colorr[ti]=1;
    }

    for(int i=1;i<n;++i)
    {
        scanf("%d%d%d",&x,&y,&z);

        add_edge(x,y,z);
        add_edge(y,x,z);
        //printf("%d\t%d\t%d\n",x,y,z);
    }

    ans=0;
    solve(1);

    printf("%d\n",ans);



    return 0;
}
