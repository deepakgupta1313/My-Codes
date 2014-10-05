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


#define MAXN 100002
#define INF 99999999999999999LL

i64 arr[MAXN][6];
i64 summs[MAXN][65];
i64 ans=-INF;
i64 mx,mn;
int n,d;




int main()
{
    freopen("Text/DISTANCE.txt","r",stdin);

    scanf("%d %d",&n,&d);

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<d;++j)
        {
            scanf("%lld",&arr[i][j]);
        }

        for(int j=0;j<=(1<<d);++j)
        {
            for(int k=0;k<d;++k)
            {
                if(j&(1<<k))
                {
                    summs[i][j]-=arr[i][k];
                }
                else
                {
                    summs[i][j]+=arr[i][k];
                }
            }
        }
    }

    for(int j=0;j<=(1<<d);++j)
    {
        mx=-INF;
        mn=INF;

        for(int i=0;i<n;++i)
        {
            if(summs[i][j]<mn)
            {
                mn=summs[i][j];
            }

            if(summs[i][j]>mx)
            {
                mx=summs[i][j];
            }
        }

        ans=max(ans,mx-mn);
    }

    printf("%lld\n",ans);

    return 0;
}
