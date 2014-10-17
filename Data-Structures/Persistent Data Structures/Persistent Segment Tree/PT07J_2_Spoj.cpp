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


//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


#define MAXN 100010

int arr[MAXN<<1],lc[20*MAXN],rc[40*MAXN],ti[MAXN],destt[MAXN<<1];
int nxt[MAXN<<1],firstt_edge[MAXN],ee=0,tot;

int id[MAXN],summ[20*MAXN],tree[MAXN],numm[MAXN],bg[MAXN],ed[MAXN],n,c=0;

inline void add_edge(int u,int v)
{
    destt[ee]=v;
    nxt[ee]=firstt_edge[u];
    firstt_edge[u]=ee++;

    destt[ee]=u;
    nxt[ee]=firstt_edge[v];
    firstt_edge[v]=ee++;
}


void dfs(int u)
{
    numm[bg[u]=++c]=arr[u];

    for(int i=firstt_edge[u];i>=0;i=nxt[i])
    {
        if(!bg[destt[i]])
        {
            dfs(destt[i]);
        }
    }

    ed[u]=c;
}

void buildd(int l,int r,int &rt)
{
    rt=++tot;
    summ[rt]=0;
    if(l==r)
    {
        return;
    }

    int midd=(l+r)>>1;

    buildd(l,midd,lc[rt]);
    buildd(midd+1,r,rc[rt]);
}


void modify(int oldd,int v,int l,int r,int &rt)
{
    rt=++tot;
    summ[rt]=summ[oldd]+1;
    lc[rt]=lc[oldd];
    rc[rt]=rc[oldd];
    if(l==r)
    {
        return;
    }

    int midd=(l+r)>>1;

    if(v<=midd)
    {
        modify(lc[oldd],v,l,midd,lc[rt]);
        return;
    }

    modify(rc[oldd],v,midd+1,r,rc[rt]);
}

int query(int l,int r,int ql,int qr,int k)
{
    if(l==r)
    {
        return l;
    }

    int ct=summ[lc[qr]]-summ[lc[ql]];
    int midd=(l+r)>>1;

    if(k<=ct)
    {
        return query(l,midd,lc[ql],lc[qr],k);
    }

    return query(midd+1,r,rc[ql],rc[qr],k-ct);
}




int main()
{
    freopen("Text/PT07J.txt","r",stdin);

    int x,y;

    n=readPosInt();
    MSET(firstt_edge,-1);
    //printf("%d\n",n);

    for(int i=1;i<=n;++i)
    {
        arr[i]=ti[i]=readPosInt();
    }

    sort(ti+1,ti+1+n);

    for(int i=1;i<=n;++i)
    {
        arr[i]=lower_bound(ti+1,ti+1+n,arr[i])-ti;
        id[arr[i]]=i;
    }

    for(int i=1;i<n;++i)
    {
        x=readPosInt();
        y=readPosInt();
        add_edge(x,y);
    }

    dfs(1);
    buildd(1,n,tree[0]);
    for(int i=1;i<=n;++i)
    {
        modify(tree[i-1],numm[i],1,n,tree[i]);
    }

    int q=readPosInt();
    //printf("%d\n",q);

    while(q--)
    {
        x=readPosInt();
        y=readPosInt();
        //printf("%d\t%d\n",x,y);

        printf("%d\n",id[query(1,n,tree[bg[x]-1],tree[ed[x]],y)]);
    }


    return 0;
}
