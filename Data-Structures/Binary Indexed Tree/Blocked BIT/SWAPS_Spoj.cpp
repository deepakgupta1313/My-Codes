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
#define PIPIPIPII pair< int, PIPIPII >
#define u64 unsigned i64


#define MAXN 250001
#define MAXV 50001
#define MAXB 501

int n,arr[MAXN],bitt[MAXV],block_bit[MAXB][MAXV];


void update(int idx,int idy,int v)
{
    for(int i=idx;i<MAXB;i+=i&-i)
    {
        for(int j=idy;j<MAXV;j+=j&-j)
        {
            block_bit[i][j]+=v;
        }
    }
}

int query(int idx,int idy)
{
    int ret=0;

    for(int i=idx;i>0;i-=i&-i)
    {
        for(int j=idy;j>0;j-=j&-j)
        {
            ret+=block_bit[i][j];
        }
    }

    return ret;
}


int solve(int pos)
{
    int x=(pos+MAXB-2)/(MAXB-1);

    int ret=query(x-1,MAXV-1)-query(x-1,arr[pos])+query(MAXB-1,arr[pos]-1)-query(x,arr[pos]-1);

    int leftt=x*(MAXB-1)-MAXB+2;
    int rightt=min(x*(MAXB-1),n);


    for(int i=leftt;i<pos;++i)
    {
        if(arr[i]>arr[pos])
        {
            ++ret;
        }
    }

    for(int i=pos+1;i<=rightt;++i)
    {
        if(arr[i]<arr[pos])
        {
            ++ret;
        }
    }

    return ret;
}



int main()
{
    freopen("Text/SWAPS.txt","r",stdin);

    i64 ans=0;
    int x,y;
    int q;

    scanf("%d",&n);

    for(int i=1;i<=n;++i)
    {
        scanf("%d",arr+i);
    }


    for(int i=n;i>0;--i)
    {
        for(int j=arr[i]-1;j>0;j-=j&-j)
        {
            ans+=bitt[j];
        }

        for(int j=arr[i];j<MAXV;j+=j&-j)
        {
            ++bitt[j];
        }

        update((i+MAXB-2)/(MAXB-1),arr[i],1);
    }


    scanf("%d",&q);

    while(q--)
    {
        scanf("%d %d",&x,&y);

        ans-=solve(x);

        int idx=(x+MAXB-2)/(MAXB-1);

        update(idx,arr[x],-1);
        update(idx,y,1);
        arr[x]=y;

        ans+=solve(x);

        printf("%lld\n",ans);
    }





    return 0;
}
