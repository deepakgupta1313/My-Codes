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


#define MAXN 18

i64 n;
int lenn;
int lnm1;
i64 tp[MAXN];
int narr[MAXN];


void pree()
{
    tp[0]=0;
    tp[1]=1;

    for(int i=2;i<MAXN;++i)
    {
        tp[i]=10*tp[i-1];
    }
}

i64 summ(i64 numm,int sign)
{
    i64 ret=0;

    while(numm)
    {
        ret+=sign*numm%10;
        sign*=-1;
        numm/=10;
    }

    return ret;
}



i64 calc(i64 numm,int nxt,int l)
{
    i64 ret=0;


    int ti=nxt+l;
    if(ti&1)
    {
        ret=(tp[l+1]>>1);
    }
    else
    {
        if(nxt&1)
        {
            ret=summ(numm,-1)*tp[l+1];
            ret+=45*tp[l];
        }
        else
        {
            ret=summ(numm,1)*tp[l+1];
        }
    }

    return ret;
}


i64 solve()
{
    i64 ret=0,numm=0;
    int sign=1;
    int i,j;
    i64 ti;

    if(n<10)
    {
        numm=1;

        while(numm<=n)
        {
            ret+=summ(numm,sign);
            if((lenn&1))
            {
                sign*=-1;
            }

            ++numm;
        }

        return ret;
    }

    for(i=0;i<lnm1;++i)
    {
        numm*=10;
        ti=narr[i];

        for(j=0;j<ti;++j)
        {
            if(numm)
            {
                ret+=calc(numm,i+1,lnm1-i);
            }
            ++numm;
        }
    }

    ret+=5;
    numm*=10;

    for(i=2;i<lenn;++i)
    {
        for(j=1;j<10;++j)
        {
            ret+=calc(j,1,i-1);
        }
    }

    if(lenn&1)
    {
        sign=-1;
    }
    else
    {
        sign=1;
    }



    while(numm<=n)
    {
        ret+=summ(numm,sign);
        if(lenn&1)
        {
            sign*=-1;
        }
        ++numm;
    }

    return ret;
}

int main()
{
    freopen("Text/KPSUM.txt","r",stdin);

    pree();
    int i;
    i64 tn;

    while(true)
    {
        scanf("%lld",&n);
        if(n==0LL)
        {
            break;
        }

        lenn=0;
        tn=n;

        while(tn)
        {
            narr[lenn++]=tn%10;
            tn/=10;
        }

        reverse(narr,narr+lenn);
        lnm1=lenn-1;

        printf("%lld\n",solve());
    }


    return 0;
}

