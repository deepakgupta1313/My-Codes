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


#define MAXN 100006

int arr[MAXN],n;
set<int> su;
int liss[MAXN];
int liss_rev[MAXN],arr_rev[MAXN];
int mx;








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



void solve(int *a1,int *b1)
{
    //printf("SOLVE\n");
    VI last_len(n+3,MAXN);
    last_len[0]=-MAXN;
    VI::iterator it;

    for(int i=0;i<n;++i)
    {
        it=lower_bound(last_len.begin(),last_len.end(),a1[i]);
        *it=a1[i];
        b1[i]=it-last_len.begin();
        //printf("LL\t%d\n",b1[i]);
        mx=max(mx,b1[i]);
    }
}



int main()
{

    freopen("Text/SUPPER.txt","r",stdin);

    int cases=10;
    set<int>::iterator it;

    while(cases--)
    {
        mx=0;
        su.clear();
        //scanf("%d",&n);
        n=readPosInt();

        for(int i=0;i<n;++i)
        {
            //scanf("%d",arr+i);
            arr[i]=readPosInt();
            arr_rev[n-1-i]=-arr[i];

        }

        solve(arr,liss);

        solve(arr_rev,liss_rev);

        for(int i=0;i<n;++i)
        {
            if((liss[i]+liss_rev[n-1-i])==(mx+1))
            {
                su.insert(arr[i]);
            }
        }


        //printf("DD\n");

        printf("%d\n",su.size());
        it=su.begin();
        printf("%d",*it);
        ++it;
        for(;it!=su.end();++it)
        {
            printf(" %d",*it);
        }



        printf("\n");
    }




    return 0;
}
