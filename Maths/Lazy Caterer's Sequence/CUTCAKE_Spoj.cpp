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

int main(){

    freopen("Text/CUTCAKE.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    i64 p,ans;

    while(cases--)
    {
        scanf("%lld",&p);
        ans=(i64)((-1.0+sqrtl(1.0-4.0*(2.0-2.0*p)))/2.0);

        if(0.5*((ans-1)*(ans-1)+ans+1)>=p && ans-1 >=0)
        {
            printf("%lld\n", ans-1);
        }
		else if(0.5*(ans*ans+ans+2)>=p && ans>=0)
        {
            printf("%lld\n", ans);
        }
		else if(0.5*((ans+1)*(ans+1)+ans+3)>=p)
        {
            printf("%lld\n", ans+1);
        }
		else
        {
            printf("%lld\n", ans+2);
        }

        //printf("%lld\n",ans);
    }
    return 0;
}




