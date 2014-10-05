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

struct doll
{
    int width,height;

    doll(int w,int h)
    {
        width=w;
        height=h;
    }
};


bool cmp_w_inc(const doll &a,const doll &b)
{
    if(a.width!=b.width)
    {
        return a.width<b.width;
    }

    return a.height>b.height;
}


struct cmp_h_dec
{
    bool operator()(const doll &a,const doll &b)
    {
        return a.height>b.height;
    }
};



int main()
{
    freopen("Text/MDOLLS.txt","r",stdin);

    int cases,m,w,h,i,p,a;

    vector<doll> sw;
    multiset<doll,cmp_h_dec> sh;
    multiset<doll,cmp_h_dec>::iterator it;

    scanf("%d",&cases);

    while(cases--)
    {
        sw.clear();
        sh.clear();

        scanf("%d",&m);

        for(i=0;i<m;++i)
        {
            scanf("%d %d",&w,&h);
            sw.PB(doll(w,h));
        }

        sort(sw.begin(),sw.end(),cmp_w_inc);

        a=0;

        for(p=0;p<m;++p)
        {
            it=sh.upper_bound(sw[p]);
            if(it!=sh.end())
            {
                sh.erase(it);
                //--a;
            }
            else
            {
                ++a;
            }

            sh.insert(sw[p]);
        }

        printf("%d\n",a);
    }

    return 0;
}
