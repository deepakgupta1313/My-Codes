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

#define MAXN 50006
#define INF 999999999

int from[MAXN],to[MAXN],weight[MAXN],n,m,src,dest,distt[MAXN];
bool poss;

int bellman_ford()
{
    int i,ti;

    poss=true;

    while(poss)
    {
        poss=false;

        for(i=1;i<=m;++i)
        {
            ti=distt[from[i]]+weight[i];
            if(ti<distt[to[i]])
            {
                distt[to[i]]=ti;
                poss=true;
            }
        }

        for(i=src;i>dest;--i)
        {
            if(distt[i]<distt[i-1])
            {
                distt[i-1]=distt[i];
                poss=true;
            }
        }

        for(i=dest+1;i<src;++i)
        {
            ti=distt[i-1]+1;
            if(ti<distt[i])
            {
                distt[i]=ti;
                poss=true;
            }
        }
    }

    return -distt[dest];
}


int main()
{
    freopen("Text/INTERVAL.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int x,y,z;

    while(cases--)
    {
        scanf("%d",&n);
        MSET(distt,0);
        MSET(to,0);
        MSET(from,0);
        MSET(weight,0);

        src=-INF;
        dest=INF;

        for(m=1;m<=n;++m)
        {
            scanf("%d %d %d",&x,&y,&z);
            from[m]=++y;
            to[m]=x;
            weight[m]=-z;

            src=max(src,y);
            dest=min(dest,x);
        }

        printf("%d\n",bellman_ford());
    }



    return 0;
}
