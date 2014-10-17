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

#define MAXN 101
#define MAXE 2700

int n,m;
int cap[MAXE],capcpy[MAXE],to[MAXE],nxt[MAXE],firstt_edge[MAXN],distt[MAXN],q[MAXN];
int headd,taill;
int st,en;

void add_edge(int u,int v,int val)
{
    to[m]=v;
    nxt[m]=firstt_edge[u];
    cap[m]=val;
    capcpy[m]=val;
    firstt_edge[u]=m++;

    to[m]=u;
    nxt[m]=firstt_edge[v];
    cap[m]=0;
    capcpy[m]=0;
    firstt_edge[v]=m++;
}


bool bfs()
{
    MSET(distt,-1);
    headd=taill=0;
    q[taill++]=st;
    distt[st]=0;
    int u;

    while(headd<taill)
    {
        u=q[headd++];

        for(int i=firstt_edge[u];i>=0;i=nxt[i])
        {
            if(cap[i]>0 && distt[to[i]]==-1)
            {
                q[taill++]=to[i];
                distt[to[i]]=distt[u]+1;
            }
        }
    }

    return distt[en]!=-1;
}


int dfs(int u,int floww)
{
    if(u==en)
    {
        return floww;
    }


    for(int i=firstt_edge[u];i>=0;i=nxt[i])
    {
        if(cap[i]>0 && distt[to[i]]==distt[u]+1)
        {
            int ret=dfs(to[i],min(floww,cap[i]));

            if(ret>0)
            {
                cap[i]-=ret;
                cap[i^1]+=ret;
                return ret;
            }
        }
    }


    return 0;
}


int max_flow(int u,int v)
{
    st=u;
    en=v;

    int ret=0;
    int x;

    while(bfs())
    {
        while(true)
        {
            x=dfs(st,INT_MAX);
            if(x==0)
            {
                break;
            }

            ret+=x;
        }
    }

    return ret;
}

int main()
{
    freopen("Text/CABLETV.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int ee;
    char buff[10];
    int u,v;
    int ans;

    while(cases--)
    {
        scanf("%d %d",&n,&ee);
        m=0;
        MSET(firstt_edge,-1);

        for(int i=0;i<n;++i)
        {
            add_edge(2*i,2*i+1,1);
        }

        for(int i=0;i<ee;++i)
        {
            scanf("%s",buff);
            sscanf(buff,"(%d, %d)",&u,&v);
            add_edge(2*u+1,2*v,n+1);
            add_edge(2*v+1,2*u,n+1);
        }

        ans=n;

        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                memcpy(cap,capcpy,sizeof(cap));

                ans=min(ans,max_flow(2*i+1,2*j));
            }
        }

        printf("%d\n",ans);
    }



    return 0;
}
