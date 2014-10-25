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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64

#define MAXN 305
#define MAXM 90610
#define INF 999999999

int n,m,first_edge[MAXN],num_edges,nxt[MAXM],to[MAXM],cap[MAXM],st,en,distt[MAXN],q[MAXN];
int headd,taill;

void add_edge(int u,int v,int uv,int vu)
{
    to[num_edges]=v;
    cap[num_edges]=uv;
    nxt[num_edges]=first_edge[u];
    first_edge[u]=num_edges++;

    to[num_edges]=u;
    cap[num_edges]=vu;
    nxt[num_edges]=first_edge[v];
    first_edge[v]=num_edges++;
}

int bfs()
{
    int u;
    headd=taill=0;

    MSET(distt,-1);

    distt[st]=0;
    q[taill++]=st;

    while(headd<taill)
    {
        u=q[headd++];
        for(int i=first_edge[u];i>-1;i=nxt[i])
        {
            if(cap[i] && distt[to[i]]==-1)
            {
                distt[to[i]]=distt[u]+1;
                q[taill++]=to[i];
            }
        }
    }

    return distt[en]!=-1;
}


int dfs(int u,int fl)
{
    if(u==en)
    {
        return fl;
    }

    int ret=0;

    for(int i=first_edge[u];i>-1;i=nxt[i])
    {
        if(cap[i] && distt[to[i]]==distt[u]+1)
        {
            ret=dfs(to[i],min(fl,cap[i]));
            if(ret)
            {
                cap[i]-=ret;
                cap[i^1]+=ret;
                return ret;
            }
        }
    }

    return 0;
}

int dinic()
{
    int ret=0,ti;

    while(bfs())
    {
        while(true)
        {
            ti=dfs(st,INF);
            if(!ti)
            {
                break;
            }
            ret+=ti;
        }
    }

    return ret;
}


int main()
{
    freopen("Text/COCONUTS.txt","r",stdin);
    int u,v;

    while(true)
    {
        scanf("%d %d",&n,&m);
        if(!n)
        {
            break;
        }

        st=0;
        en=n+1;
        num_edges=0;
        MSET(first_edge,-1);

        for(int i=1;i<=n;++i)
        {
            scanf("%d",&v);
            if(v)
            {
                add_edge(st,i,1,0);
            }
            else
            {
                add_edge(i,en,1,0);
            }
        }

        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&u,&v);
            add_edge(u,v,1,1);
        }

        printf("%d\n",dinic());
    }


    return 0;
}
