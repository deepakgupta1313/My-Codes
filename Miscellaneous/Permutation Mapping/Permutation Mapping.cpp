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

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define LD long double
#define SZOF(x) sizeof((x))


int factorial(int num)
{
    int i,ret=1;

    FOR(i,2,num+1)
    {
        ret*=i;
    }

    return ret;
}

void prVect(VI a)
{
    int i;
    REP(i,a.size())
    {
        printf("%d\t",a[i]);
    }

    printf("\n");
}



int encode(VI a)
{
    int len=a.size();
    int i;

    if(len==2 || len==1)
    {
        return a[0];
    }

    int sum=0;

    sum+=a[0]*factorial(len-1);

    VI r;

    FOR(i,1,len)
    {
        r.PB(a[i]);
        if(r[i-1]>a[0])
        {
            --r[i-1];
        }
    }

    return sum+encode(r);
}



VI decode(int val,int len)
{
    VI ret;
    int i;
    if(len==1)
    {
        ret.PB(0);
        return ret;
    }

    ret.PB(val/(factorial(len-1)));
    val%=factorial(len-1);

    VI t=decode(val,len-1);

    FOR(i,0,len-1)
    {
        if(t[i]>=ret[0])
        {
            ++t[i];
        }
        ret.PB(t[i]);
    }

    return ret;
}

int main()
{

    freopen("Permutation Mapping.txt","r",stdin);

    vector<int> a;

    int t,i,n;

    scanf("%d",&n);
    //cout<<n<<endl;

    REP(i,n)
    {
        scanf("%d",&t);
        a.PB(t);
    }

    prVect(a);

    printf("%d\n",encode(a));

    prVect(decode(encode(a),n));


	return 0;
}
