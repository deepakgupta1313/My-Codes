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

const u64 mod = 1000000007;
u64 val;

int main(){

    freopen("Text/WEIRDFN.txt","r",stdin);
	u64 a,b,c,n,i,ti,sl,sr,summ;
	int cases;
	scanf("%d",&cases);

	while(cases--)
    {
        priority_queue < int, vector<int>, less<int> > left;
        priority_queue < int, vector<int>, greater<int> > right;

        scanf("%llu %llu %llu %llu",&a,&b,&c,&n);

        left.push(1);
        val = 1;
        sl = 1;
        sr = 0;
        summ = 1;

        for(i=2;i<=n;i++)
        {
            ti = left.top();
            val = a*ti + (b*i) + c;

            if(val>=mod)
            {
                val%=mod;
            }

            summ += val;
            if(sl>sr)
            {
                if(val<ti)
                {
                    left.pop();
                    right.push(ti);
                    left.push(val);
                }
                else
                {
                    right.push(val);
                }

                sr++;
            }
            else
            {
                ti = right.top();
                if(val>ti)
                {
                    right.pop();
                    left.push(ti);
                    right.push(val);
                }
                else
                {
                    left.push(val);
                }

                sl++;
            }
        }

        printf("%llu\n",summ);
    }

    return 0;
}
