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
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}


#define MAXF 50000000
#define MAXE 105

int par[MAXE];
int src,snk;
int e,a,b,f;
int xs[MAXE],ys[MAXE];

int findd(int x)
{
    if(par[x]!=x)
    {
        par[x]=findd(par[x]);
    }

    return par[x];
}

int gcdd2(int x,int y)
{
    if(y==0)
    {
        return x;
    }

    return gcdd2(y,x%y);
}

int gcdd(int x,int y)
{
    if(x<y)
    {
        return gcdd2(y,x);
    }

    return gcdd2(x,y);
}

bool visits(int elevv,int floorr)
{
    return ((floorr>=ys[elevv]) && ((floorr-ys[elevv])%xs[elevv]==0));
}

bool do_meet(int x,int y)
{

    int gg,lcmm,mx,diff,ti1,ti2,st,i;


    gg=gcdd(xs[x],xs[y]);
    lcmm=xs[x]*xs[y]/gg;
    mx=max(ys[x],ys[y]);
    diff=mx-min(ys[x],ys[y]);



    if(diff%gg)
    {
        return 0;
    }

    if((f-mx)>=lcmm)
    {
        return 1;
    }

    ti1=(xs[x]>xs[y])?x:y;
    ti2=(xs[x]>xs[y])?y:x;

    st= xs[ti1]*((mx - ys[ti1] + xs[ti1] - 1)/xs[ti1]) + ys[ti1];
    i=0;


    while(true)
    {
        if (st + xs[ti1]*i >= f) return 0;
        if (visits(ti2, st + xs[ti1]*i)) return 1;
        ++i;
    }


    return 0;
}

int main()
{
    freopen("Text/SCRAPER.txt","r",stdin);
    int x,y;
    int cases;
    int px,py;

    scanf("%d",&cases);
    //cases=readPosInt();
    int i,j;
    bool poss;

    while(cases--)
    {
        scanf("%d %d %d %d",&f,&e,&a,&b);
        //f=readPosInt();
        //e=readPosInt();
        //a=readPosInt();
        //b=readPosInt();
        poss=false;
        src=e+1;
        snk=e+2;

        for(i=1;i<=e+2;++i)
        {
            par[i]=i;
        }

        for(i=1;i<=e;++i)
        {
            scanf("%d %d",xs+i,ys+i);
            //xs[i]=readPosInt();
            //ys[i]=readPosInt();
        }

        for(i=1;i<=e;++i)
        {
            for(j=i+1;j<=e;++j)
            {
                if(do_meet(i,j))
                {
                    px=findd(i);
                    py=findd(j);
                    par[py]=px;
                }
            }
        }

        for(i=1;i<=e;++i)
        {
            if(visits(i,a))
            {
                px=findd(i);
                py=findd(e+1);
                par[px]=py;
            }
        }

        for(i=1;i<=e;++i)
        {
            if(visits(i,b))
            {
                px=findd(i);
                py=findd(e+2);
                par[px]=py;
            }
        }

        px=findd(e+1);
        py=findd(e+2);

        if(px==py)
        {
            poss=true;
        }

        if(a==b)
        {
            poss=true;
        }

        if(poss)
        {
            printf("It is possible to move the furniture.\n");
        }
        else
        {
            printf("The furniture cannot be moved.\n");
        }
    }



    return 0;
}
