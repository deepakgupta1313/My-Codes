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

#define MAXN 100004
char s[MAXN];
int lenn;
int z[MAXN];


void revv()
{
    int ti=lenn-1;
    int midd=lenn/2;

    for(int i=0;i<midd;++i)
    {
        swap(s[i],s[ti-i]);
    }
}

void zarr()
{
    MSET(z,0);
    int l=0,r=0;
    int k;

    for(int i=1;i<lenn;++i)
    {
        if(i>r)
        {
            l=r=i;

            while(r<lenn && s[r-l]==s[r])
            {
                ++r;
            }
            z[i]=r-l;
            --r;
        }
        else
        {
            k=i-l;

            if(z[k]<r-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                l=i;
                while(r<lenn && s[r-l]==s[r])
                {
                    ++r;
                }
                z[i]=r-l;
                --r;
            }
        }
    }

    z[0]=lenn;
}

void solve()
{
    zarr();
}

int main()
{
    freopen("Text/QUERYSTR.txt","r",stdin);
    int cases;
    scanf("%d",&cases);

    int ti;
    int m;

    while(cases--)
    {
        scanf("%s",s);
        //printf("%s\n",s);
        lenn=strlen(s);
        revv();
        solve();

        scanf("%d",&m);
        //printf("%d\n",m);

        while(m--)
        {
            scanf("%d",&ti);
            //printf("%d\n",ti);
            printf("%d\n",z[lenn-ti]);
        }
    }
    return 0;
}
