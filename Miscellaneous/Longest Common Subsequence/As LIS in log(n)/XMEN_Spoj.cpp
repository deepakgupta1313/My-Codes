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

#define MAXN 100001

int arr[MAXN],barr[MAXN],carr[MAXN];
VI::iterator it;

VI larr;
int n;


void liss()
{

    for(int i=0;i<n;++i)
    {
        it=upper_bound(larr.begin(),larr.end(),carr[i]);

        if(it==larr.end())
        {
            larr.PB(carr[i]);
        }
        else
        {
            *it=carr[i];
        }
    }

    printf("%d\n",larr.size());
}

int main()
{
    freopen("Text/XMEN.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        larr.clear();
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            --arr[i];
            barr[arr[i]]=i;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            --arr[i];
            carr[i]=barr[arr[i]];
        }

        liss();
    }


    return 0;
}
