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

#define MAXN 100003

struct pointt
{
    int x,y;
};

pointt arr[MAXN];
pointt convex_hull[MAXN];

int n,m;
pointt p0;

inline i64 ccw(pointt a,pointt b,pointt c)
{
    return (i64)((i64)((i64)(b.x-a.x)*(i64)(c.y-a.y))-(i64)((i64)(c.x-a.x)*(i64)(b.y-a.y)));
}

inline i64 distt(pointt a,pointt b)
{
    return (i64)((i64)((i64)(a.x-b.x)*(i64)(a.x-b.x))+(i64)((i64)(a.y-b.y)*(i64)(a.y-b.y)));
}

inline bool cmp(pointt a,pointt b)
{
    i64 ti=ccw(p0,b,a);
    if(ti<0)
    {
        return 1;
    }

    if(ti>0)
    {
        return 0;
    }

    return distt(p0,a)<distt(p0,b);
}

inline void graham_scan()
{
    int st=1;

    for(int i=2;i<=n;++i)
    {
        if(arr[st].y>arr[i].y || (arr[st].y==arr[i].y && arr[st].x<arr[i].x))
        {
            st=i;
        }
    }

    swap(arr[1],arr[st]);

    p0=arr[1];

    sort(arr+2,arr+n+1,cmp);

    m=1;

    convex_hull[1]=p0;

    for(int i=2;i<=n;++i)
    {
        while(m>=2 && ccw(convex_hull[m-1],convex_hull[m],arr[i])<0)
        {
            --m;
        }

        convex_hull[++m]=arr[i];
    }
}


inline i64 rotating_calliper()
{
    if(m==1)
    {
        return 0;
    }

    if(m==2)
    {
        return distt(convex_hull[1],convex_hull[2]);
    }


    int k=2;
    i64 ans=0;

    while((k<m) && abs(ccw(convex_hull[m],convex_hull[1],convex_hull[k+1]))>abs(ccw(convex_hull[m],convex_hull[1],convex_hull[k])))
    {
        ++k;
    }

    int j=k;

    for(int i=1;i<=k;++i)
    {
        ans=max(ans,distt(convex_hull[i],convex_hull[j]));

        while((j<m) && abs(ccw(convex_hull[i],convex_hull[i+1],convex_hull[j+1]))>abs(ccw(convex_hull[i],convex_hull[i+1],convex_hull[j])))
        {
            ++j;
        }

        ans=max(ans,distt(convex_hull[i],convex_hull[j]));
    }

    return ans;
}


int main()
{
    freopen("Text/TFOSS.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        m=0;
        MSET(convex_hull,0);
        MSET(arr,0);
        scanf("%d",&n);

        for(int i=1;i<=n;++i)
        {
            scanf("%d %d",&arr[i].x,&arr[i].y);
        }

        graham_scan();

        printf("%lld\n",rotating_calliper());
    }



    return 0;
}

