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
#define VLL vector<i64>


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



#define MOD 1000000007

//#define gc getchar_unlocked
#define gc getchar


inline i64 readPosLLD()
{
    i64 ret=0;
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

inline i64 readLLD()
{
    i64 ret=0;
    bool negg=false;
    char c;
    c=gc();

    while((c<'0' || c>'9') && c!='-')
    {
        //scanf("%c",&c);
        c=gc();
    }

    if(c=='-')
    {
        negg=true;
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    if(negg)
    {
        ret=-ret;
    }

    return ret;
}



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

inline int readInt()
{
    int ret=0;
    bool negg=false;
    char c;
    c=gc();

    while((c<'0' || c>'9') && c!='-')
    {
        //scanf("%c",&c);
        c=gc();
    }

    if(c=='-')
    {
        negg=true;
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    if(negg)
    {
        ret=-ret;
    }

    return ret;
}

VLL a,psum;

i64 nth_rt(i64 x,int k)
{

    if(k==1)
    {
        return x;
    }

    double powRoot=1.0/k;
    double origRoot=pow(x,powRoot);

    i64 root=origRoot;
    i64 root2=origRoot + 1e-7;

    if(root != root2)
    {
        double nextPow=pow(root2,k);

        if(nextPow<x || fabs(nextPow - x)<=1e-6)
        {
            return root2;
        }
    }

    return root;
}


int main()
{

    freopen("FUNC_Codechef.txt","r",stdin);

    int cases,i,j;
    int n,q,ti;
    i64 x,res,rt,tll;

    scanf("%d",&cases);
    //printf("DD\n");
    while(cases--)
    {


        a.clear();
        psum.clear();
        scanf("%d %d",&n,&q);

        REP(i,n)
        {
            //printf("DD\n");
            scanf("%d",&ti);
            ti%=MOD;
            if(ti<0)
            {
                ti+=MOD;
            }
            a.PB(ti);
            psum.PB(0);

            if(i)
            {
                psum[i]+=psum[i-1]+a[i];
            }
            else
            {
                psum[i]=a[i];
            }

            psum[i]%=MOD;
        }

        REP(j,q)
        {

            scanf("%lld",&x);

            res=0;

            REP(i,n)
            {
                rt=nth_rt(x,i+1);

                if(rt>1)
                {
                    res+=((rt%MOD)*a[i])%MOD;
                    res%=MOD;
                }
                else
                {
                    tll=psum[n-1];

                    if(i!=0)
                    {
                        tll-=psum[i-1];
                    }

                    tll%=MOD;
                    if(tll<0)
                    {
                        tll+=MOD;
                    }
                    res+=tll;
                    res%=MOD;
                    break;
                }
            }

            if(j)
            {
                printf(" ");
            }

            printf("%d",res);
        }

        printf("\n");
    }

	return 0;
}
