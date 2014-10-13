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

i64 n,p;


i64 poww(i64 a,i64 b)
{
    i64 ret=1L;

    while(b)
    {
        if(b&1)
        {
            ret*=a;
            ret%=p;
        }
        b>>=1;
        a*=a;
        a%=p;
    }

    return ret;
}

i64 invv(int numm)
{
    return poww(numm,p-2);
}


i64 solve()
{
    if(n>=p)
    {
        return 0L;
    }

    i64 ret=p-1;
    i64 ti;

    for(i64 i=n+1;i<p;++i)
    {
        ti=invv(i);
        ret*=ti;
        ret%=p;
    }

    return ret;
}

int main()
{
    freopen("Text/DCEPC11B.txt","r",stdin);
    int cases,ct;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lld %lld",&n,&p);

        printf("%lld\n",solve());
    }




    return 0;
}
