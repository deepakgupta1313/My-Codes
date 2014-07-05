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

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}



//#define gc getchar_unlocked
#define gc getchar



inline i64 readPosLLD()
{
    i64 ret=0;
    char c;
    c=gc();

    while(c!=EOF && (c<'0' || c>'9'))
    {
        //scanf("%c",&c);
        c=gc();
        //printf("DD\n");
    }

    while((c>='0' && c<='9'))
    {
        ret=ret*10+(c-'0');
        c=gc();
        //printf("MM\n");
    }

    return ret;
}

#define MOD 1000000007
#define ULL unsigned long long
//#define INV 333333336

i64 INV;

ULL pow_mod(ULL n)
{
    ULL x=1,p=2;
    while(n)
    {
        if(n&1)
        {
            x=(x*p)%MOD;
        }

        p=(p*p)%MOD;
        n>>=1;
    }

    return x;
}

int fast_pow(i64 base,i64 n,i64 M)
{
    if(n==0)
    {
        return 1;
    }

    if(n==1)
    {
        return base;
    }

    i64 halfn=fast_pow(base,n/2,M);

    if((n%2)==0)
    {
        return ( halfn * halfn ) % M;
    }
    else
    {
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
    }
}

int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}

int main()
{
    freopen("DIVISION_Spoj.txt","r",stdin);
    ULL n, result;

    INV=findMMI_fermat(3,MOD);
    //cout<<INV<<endl;

    while(scanf("%llu",&n)!=EOF)
    {
        if(n&1)
        {
            result=((pow_mod(n)+1)*INV)%MOD;
        }
        else
        {
            result=((pow_mod(n)+2)*INV)%MOD;
        }

        printf("%llu\n",result);
    }

	return 0;
}
