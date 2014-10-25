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

#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536



i64 stirling(double n)
{
    double ret;

    ret=n*log(n)-n+0.5*log(2*M_PI*n)+(1.0/12.0/n)-(1.0/360.0/n/n/n)+(1.0/1260.0/n/n/n/n/n)-(1.0/1680/n/n/n/n/n/n/n);

    return ((i64)(ret*log10(M_E))+1LL);
}

int main()
{
    freopen("Text/FUNFACT.txt","r",stdin);

    int cases;
    int n;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        ++n;
        i64 l=1,r=1LL<<31,midd;

        while(l<r)
        {
            midd=(l+r)>>1;
            if(stirling(midd)<n)
            {
                l=midd+1;
            }
            else
            {
                r=midd;
            }
        }

        printf("%lld\n",l-1);
    }

    return 0;
}
