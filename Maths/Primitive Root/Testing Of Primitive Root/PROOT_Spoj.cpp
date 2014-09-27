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

#define MAX 46656
#define LMT 216
#define PRLEN 4830

bitset<MAX> flag;
int primes[PRLEN];
int plen;

int factor[50];


void sieve()
{
    int i,j,k;

    for(i=3;i<LMT;i+=2)
    {
        if(!flag.test(i))
        {
            for(j=i*i,k=i<<1;j<MAX;j+=k)
            {
                flag.set(j);
            }
        }
    }

    primes[0]=2;

    for(i=3,j=1;i<MAX;i+=2)
    {
        if(!flag.test(i))
        {
            primes[j++]=i;
        }
    }

    plen=j;
}


int factorize(int n)
{
    int i,lmt=sqrt(n),k=0;

    for(i=0;primes[i]<=lmt;++i)
    {
        if(n%primes[i]==0)
        {
            factor[k++]=primes[i];

            while(n%primes[i]==0)
            {
                n/=primes[i];
            }
            lmt=sqrt(n);
        }
    }

    if(n>1)
    {
        factor[k++]=n;
    }

    return k;
}


int mod_exp(i64 b,i64 e,int m)
{
    i64 ret=1;

    while(e>0)
    {
        if(e&1)
        {
            ret*=b;
            ret%=m;
        }
        e>>=1;
        b*=b;
        b%=m;
    }

    return ret;
}

int main(){

    freopen("Text/PROOT.txt","r",stdin);

    int m,n,t,i,j,p,phi,sz;

    sieve();

    while(true)
    {
        scanf("%d %d",&n,&t);

        if(n==0 && t==0)
        {
            break;
        }

        phi=n-1;

        sz=factorize(phi);

        for(int i=0;i<t;++i)
        {
            scanf("%d",&m);

            for(j=0;j<sz;++j)
            {
                p=phi/factor[j];

                if(mod_exp(m,p,n)==1)
                {
                    break;
                }
            }

            if(j==sz)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }

    return 0;
}




