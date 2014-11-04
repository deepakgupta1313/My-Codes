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


//#define gc getchar_unlocked
#define gc getchar

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}



#define MAXN 30015


vector<int> ans;
vector<int> parentt,ancestor,childd,vertexx;
vector<int> label,semi,sizee;

int n,m;
VVI succ,predd,bucket;
//int ans[MAXN],parentt[MAXN],ancestor[MAXN],childd[MAXN],vertexx[MAXN],label[MAXN],semi[MAXN],sizee[MAXN];
int ct;


inline void dfs(int nodee)
{
    int i;
    semi[nodee]=++n;
    vertexx[n]=label[nodee]=nodee;
    ancestor[nodee]=childd[nodee]=0;
    sizee[nodee]=1;
    int w;

    for(i=0;i<succ[nodee].size();++i)
    {
        w=succ[nodee][i];
        if(!semi[w])
        {
            parentt[w]=nodee;
            dfs(w);
        }
        predd[w].PB(nodee);
    }
}

inline void compress(int nodee)
{
    if(ancestor[ancestor[nodee]])
    {
        compress(ancestor[nodee]);
        if(semi[label[ancestor[nodee]]]<semi[label[nodee]])
        {
            label[nodee]=label[ancestor[nodee]];
            ancestor[nodee]=ancestor[ancestor[nodee]];
        }
    }
}

inline int eval(int nodee)
{
    if(!ancestor[nodee])
    {
        return label[nodee];
    }

    compress(nodee);
    return semi[label[ancestor[nodee]]]>=semi[label[nodee]]?label[nodee]:label[ancestor[nodee]];
}


inline void linkk(int par,int nodee)
{
    int ti=nodee;

    while(semi[label[nodee]]<semi[label[childd[ti]]])
    {
        if(sizee[ti]+sizee[childd[childd[ti]]]>=(sizee[childd[ti]]<<1))
        {
            ancestor[childd[ti]]=ti;
            childd[ti]=childd[childd[ti]];
        }
        else
        {
            sizee[childd[ti]]=sizee[ti];
            ti=ancestor[ti]=childd[ti];
        }
    }

    label[ti]=label[nodee];
    sizee[par]+=sizee[nodee];

    if(sizee[par]<(sizee[nodee]<<1))
    {
        swap(ti,childd[par]);
    }

    while(ti)
    {
        ancestor[ti]=par;
        ti=childd[ti];
    }
}

inline void dominators()
{
    ans=parentt=ancestor=childd=vertexx=label=semi=sizee=vector<int>(n+1,0);



    //MSET(ans,0);
    //MSET(parentt,0);
    //MSET(vertexx,0);

/*
    MSET(ancestor,0);
    MSET(childd,0);
    MSET(label,0);
    MSET(semi,0);
    MSET(sizee,0);
*/

    bucket=VVI(n+1);
    int r=n;
    n=0;

    dfs(r);
    int u,v,w;
    int i,j;

    for(i=n;i>=2;--i)
    {
        w=vertexx[i];

        for(j=0;j<predd[w].size();++j)
        {
            v=predd[w][j];
            u=eval(v);

            semi[w]=min(semi[u],semi[w]);
        }

        bucket[vertexx[semi[w]]].PB(w);
        linkk(parentt[w],w);

        for(j=0;j<bucket[parentt[w]].size();++j)
        {
            v=bucket[parentt[w]][j];
            u=eval(v);
            ans[v]=semi[u]<semi[v]?u:parentt[w];
        }
    }

    for(i=2;i<=n;++i)
    {
        w=vertexx[i];
        if(ans[w]!=vertexx[semi[w]])
        {
            ans[w]=ans[ans[w]];
        }
    }
    ans[n]=0;
}



int main()
{
    freopen("Text/EN.txt","r",stdin);

    int cases;

    //scanf("%d",&cases);
    cases=readPosInt();
    int x,y;
    int i;

    while(cases--)
    {

        ct=0;
        //scanf("%d %d",&n,&m);
        n=readPosInt();
        m=readPosInt();

        succ=VVI(n+1);
        predd=VVI(n+1);

        for(i=0;i<m;++i)
        {
            //printf("DD\n");
            //scanf("%d %d",&x,&y);
            x=readPosInt();
            y=readPosInt();
            succ[y].PB(x);
            //predd[x].PB(y);
        }

        dominators();

        printf("%d\n",ans[1]);
    }


    return 0;
}

