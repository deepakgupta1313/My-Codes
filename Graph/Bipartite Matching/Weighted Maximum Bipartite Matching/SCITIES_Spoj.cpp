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


#define MAXN 202
#define MAXE 20400
#define INF 0x3f3f3f3f

int src,snk,num_node,num_edge;
int fin[MAXN],pre[MAXN],dist[MAXN];
int cap[MAXE],cost[MAXE],nxt[MAXE],to[MAXE],from[MAXE];

inline void init(int sr,int sn,int nodes)
{
    MSET(fin,-1);
    num_node=nodes;
    num_edge=0;
    src=sr;
    snk=sn;
}


inline void add_edge(int u,int v,int _cap,int _cost)
{
    from[num_edge]=u;
    to[num_edge]=v;
    cap[num_edge]=_cap;
    cost[num_edge]=_cost;
    nxt[num_edge]=fin[u];
    fin[u]=num_edge++;

    from[num_edge]=v;
    to[num_edge]=u;
    cap[num_edge]=0;
    cost[num_edge]=-_cost;
    nxt[num_edge]=fin[v];
    fin[v]=num_edge++;
}


bool bellman()
{
    int iter,u,v,i;
    bool flagg=true;
    MSET(dist,0x7f);
    MSET(pre,-1);
    dist[src]=0;

    for(iter=1;iter<num_node && flagg ;++iter)
    {
        flagg=false;
        for(u=0;u<num_node;++u)
        {
            for(i=fin[u];i>=0;i=nxt[i])
            {
                v=to[i];
                if(cap[i] && dist[v]>dist[u]+cost[i])
                {
                    dist[v]=dist[u]+cost[i];
                    pre[v]=i;
                    flagg=true;
                }
            }
        }
    }

    return (dist[snk]<INF);
}


int min_cost_max_flow(int &fcost)
{
    int netflow,bot,u;
    netflow=fcost=0;

    while(bellman())
    {
        bot=INF;

        for(u=pre[snk];u>=0;u=pre[from[u]])
        {
            bot=min(bot,cap[u]);
        }

        for(u=pre[snk];u>=0;u=pre[from[u]])
        {
            cap[u]-=bot;
            cap[u^1]+=bot;
            fcost+=bot*cost[u];
        }

        netflow+=bot;
    }

    return netflow;
}



int main() {

    freopen("Text/SCITIES.txt","r",stdin);

    int n1,n2,cases,u,v,w,i;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n1,&n2);
        init(0,n1+n2+1,n1+n2+2);

        for(i=1;i<=n1;++i)
        {
            add_edge(0,i,1,0);
        }

        for(i=1;i<=n2;++i)
        {
            add_edge(n1+i,n1+n2+1,1,0);
        }

        while(scanf("%d %d %d",&u,&v,&w)==3 && (u+v+w))
        {
            add_edge(u,n1+v,1,-w);
        }

        min_cost_max_flow(w);
        printf("%d\n",-w);
    }


	return 0;
}
