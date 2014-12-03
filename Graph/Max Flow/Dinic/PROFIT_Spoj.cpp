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
#include <cassert>
#include<cmath>


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
#define Vi64 vector<i64>
#define Vu64 vector<u64>


#define MAXN 55005
#define MAXE 310000
#define INF 99999999

int src,snk,e;
int q[MAXN],firstt[MAXN],tmp[MAXN],distt[MAXN];
int floww[MAXE],cap[MAXE],nxt[MAXE],to[MAXE];


void add_edge(int x,int y,int v)
{
    to[e]=y;
    cap[e]=v;
    floww[e]=0;
    nxt[e]=firstt[x];
    firstt[x]=e++;

    to[e]=x;
    cap[e]=0;
    floww[e]=0;
    nxt[e]=firstt[y];
    firstt[y]=e++;
}


bool bfs()
{
    int st,en,i,u,v;
    MSET(distt,-1);

    distt[src]=st=en=0;
    q[en++]=src;

    while(st<en)
    {
        u=q[st++];
        for(i=firstt[u];i>=0;i=nxt[i])
        {
            v=to[i];

            if(floww[i] < cap[i] && distt[v]==-1)
            {
                distt[v]=distt[u]+1;
                q[en++]=v;
            }
        }
    }

    return distt[snk]!=-1;
}

int dfs(int u,int fl)
{
    if(u==snk)
    {
        return fl;
    }

    for(int &i=tmp[u],v,ret;i>=0;i=nxt[i])
    {
        v=to[i];

        if(floww[i]<cap[i] && distt[v]==distt[u]+1)
        {
            ret=dfs(v,min(fl,(cap[i]-floww[i])));
            if(ret>0)
            {
                floww[i]+=ret;
                floww[i^1]-=ret;
                return ret;
            }
        }
    }

    return 0;
}

int dinitz()
{
    int ret=0;
    int ti=0;

    while(bfs())
    {
        memcpy(tmp,firstt,sizeof(tmp));
        while(true)
        {
            ti=dfs(src,INF);
            if(ti)
            {
                ret+=ti;
            }
            else
            {
                break;
            }
        }
    }

    return ret;
}



int main()
{
    freopen("Text/PROFIT.txt","r",stdin);
    int cases,n,m,i,u,v,w,ans;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&m);

        e=0;
        src=1;
        snk=n+m+2;
        MSET(firstt,-1);

        for(i=1;i<=n;++i)
        {
            scanf("%d",&w);
            add_edge(1,1+i,w);
        }

        for(i=1,ans=0;i<=m;++i)
        {
            scanf("%d %d %d",&u,&v,&w);
            ans+=w;
            add_edge(1+n+i,snk,w);
            add_edge(1+u,1+n+i,INF);
            add_edge(1+v,1+n+i,INF);
        }

        ans-=dinitz();
        printf("%d\n",ans);

    }



    return 0;
}

