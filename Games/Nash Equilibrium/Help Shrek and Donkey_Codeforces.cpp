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

#define MAXN 1010

double dp[MAXN][MAXN];

int m,n;

double solve(int m,int n)
{
    if(m==0 || n==0)
    {
        return 1/(n+1.0);
    }

    if(dp[m][n]>0)
    {
        return dp[m][n];
    }

    double a,b,c,d,p;

    a=1.0;
    b=1.0-solve(n,m-1);

    c=(double)n/(n+1)*(1-solve(n-1,m));
    d=c+1.0/(n+1);

    p=(d-b)/(a-b-c+d);
    dp[m][n]=p*a+(1-p)*b;

    return dp[m][n];
}

int main()
{
    freopen("Text/Help Shrek and Donkey.txt","r",stdin);

    MSET(dp,0);

    scanf("%d %d",&m,&n);

    printf("%.10f %.10f\n",solve(m,n),1-solve(m,n));



    return 0;
}
