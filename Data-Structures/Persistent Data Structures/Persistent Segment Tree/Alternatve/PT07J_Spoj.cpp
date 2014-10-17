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

#define MAXN 111111
#define MAXD 18

int tot,cnt,arr[MAXN],barr[MAXN],carr[MAXN],darr[MAXD][MAXN],sarr[MAXD][MAXN];
int firstt_edge[MAXN],bg[MAXN],ed[MAXN],destt[MAXN<<1],nxt[MAXN<<1];


bool cmpp(int x,int y)
{
    return arr[barr[x]]<arr[barr[y]];
}


inline void add_edge(int u,int v)
{
    destt[++tot]=v;
    nxt[tot]=firstt_edge[u];
    firstt_edge[u]=tot;
}


void dfs(int u)
{
    barr[bg[u]=++cnt]=u;

    for(int ee=firstt_edge[u];ee;ee=nxt[ee])
    {
        if(!bg[destt[ee]])
        {
            dfs(destt[ee]);
        }
    }

    ed[u]=cnt;
}

void buildd(int h,int f,int t)
{
    if(f==t)
    {
        return;
    }

    int midd=(f+t)>>1;
    int l=0;

    for(int i=f;i<=t;++i)
    {
        if(darr[h][i]<=midd)
        {
            darr[h+1][f+l]=darr[h][i];
            sarr[h][i]=++l;
        }
        else
        {
            darr[h+1][midd+1+i-f-l]=darr[h][i];
            sarr[h][i]=l;
        }
    }

    buildd(h+1,f,midd);
    buildd(h+1,midd+1,t);
}


int query(int h,int f,int t,int qf,int qt,int k)
{
    if(f==t)
    {
        return darr[h][f];
    }

    int midd=(f+t)>>1;
    int l= qf==f?0:sarr[h][qf-1];
    int r=sarr[h][qt];

    if(r-l<k)
    {
        return query(h+1,midd+1,t,midd+1+qf-f-l,midd+1+qt-f-r,k-r+l);
    }

    return query(h+1,f,midd,f+l,f+r-1,k);
}




int main()
{
    freopen("Text/PT07J.txt","r",stdin);

    int n,m;
    int u,v;

    scanf("%d",&n);

    for(int i=1;i<=n;++i)
    {
        scanf("%d",&arr[carr[i]=i]);
    }

    for(int i=1;i<n;++i)
    {
        scanf("%d %d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }

    dfs(1);

    sort(carr+1,carr+1+n,cmpp);

    for(int i=1;i<=n;++i)
    {
        darr[0][carr[i]]=i;
    }

    buildd(0,1,n);

    scanf("%d",&m);

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&u,&v);
        printf("%d\n",barr[carr[query(0,1,n,bg[u],ed[u],v)]]);
    }


    return 0;
}
