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
#define Vi64 vector<i64>
#define Vu64 vector<u64>


const int MAXN=1018;
const int INF=~0U>>1;

int n,src,dest,tot,ans;

int firstt[MAXN],dist[MAXN],prevv[MAXN],que_next[MAXN];
bool in_que[MAXN];

struct edge
{
    int to;
    int next_edge;
    int capacityy;
    int costt;
}edge_arr[MAXN*8];

void add_edge(int x,int y,int cap,int cst)
{
    edge_arr[++tot].to=y;
    edge_arr[tot].next_edge=firstt[x];
    edge_arr[tot].capacityy=cap;
    edge_arr[tot].costt=cst;
    firstt[x]=tot;

    edge_arr[++tot].to=x;
    edge_arr[tot].next_edge=firstt[y];
    edge_arr[tot].capacityy=0;
    edge_arr[tot].costt=-cst;
    firstt[y]=tot;
}


bool spfa()
{
    MSET(dist,0x3F);
    int mx=dist[0];
    MSET(que_next,0);
    MSET(in_que,0);
    dist[src]=0;

    int now=src,endd=src,dt;

    for(int i,p,pos;now;now=que_next[pos],que_next[pos]=0)
    {
        for(in_que[pos=now]=false,i=firstt[pos],p=edge_arr[i].to;i;i=edge_arr[i].next_edge,p=edge_arr[i].to)
        {
            if(edge_arr[i].capacityy && (dt=dist[pos]+edge_arr[i].costt)<dist[p])
            {
                dist[p]=dt;
                prevv[p]=i;

                if(!in_que[p])
                {
                    que_next[endd]=p;
                    in_que[p]=true;
                    endd=p;
                }
            }
        }
    }

    //printf("DD\t%d\t%d\n",dist[dest],mx);

    return dist[dest]!=mx;
}


void augment()
{
    int flow=INF;
    for(int i=dest;i!=src;i=edge_arr[prevv[i]^1].to)
    {
        if(edge_arr[prevv[i]].capacityy<flow)
        {
            flow=edge_arr[prevv[i]].capacityy;
        }
    }

    for(int i=dest;i!=src;i=edge_arr[prevv[i]^1].to)
    {
        edge_arr[prevv[i]].capacityy-=flow;
        edge_arr[prevv[i]^1].capacityy+=flow;
        ans+=edge_arr[prevv[i]].costt*flow;
    }
}




int main() {

	freopen("Text/BOXES.txt","r",stdin);

	int cases;

	scanf("%d",&cases);

	while(cases--)
    {
        MSET(firstt,0);
        tot=1;
        ans=0;

        scanf("%d",&n);

        src=n+1;
        dest=n+2;

        for(int i=1,c;i<=n;++i)
        {
            scanf("%d",&c);
            //printf("%d\n",c);

            if(i>1)
            {
                add_edge(i,i-1,INF,1);
            }
            else
            {
                add_edge(i,n,INF,1);
            }

            if(i<n)
            {
                add_edge(i,i+1,INF,1);
            }
            else
            {
                add_edge(i,1,INF,1);
            }

            add_edge(src,i,c,0);
            add_edge(i,dest,1,0);
        }

        while(spfa())
        {
            augment();
        }
        printf("%d\n",ans);
    }


    return 0;
}
