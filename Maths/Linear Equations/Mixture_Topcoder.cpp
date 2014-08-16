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



#define INF 2000000000

const int maxn=11;
const double eps=1e-4;

typedef double arr[maxn][maxn];
typedef double arr1[maxn];

arr1 x,a,tmp;
arr g,b;

int n,m;
double ans;
double p[maxn],cst[maxn];






class Mixture  {
	public:


    void solve()
    {

        int r=0,c=0;

        while(r<m && c<n)
        {
            int k=r;

            for(int i=r+1;i<m;++i)
            {
                if(abs(g[i][c])>abs(g[k][c]))
                {
                    k=i;
                }
            }

            if(abs(g[k][c])<eps)
            {
                return;
            }


            memcpy(tmp,g[r],sizeof(arr1));
            memcpy(g[r],g[k],sizeof(arr1));
            memcpy(g[k],tmp,sizeof(arr1));

            for(k=r+1;k<m;++k)
            {
                if(abs(g[k][c])>eps)
                {
                    double t=g[k][c]/g[r][c];

                    for(int i=c;i<=n;++i)
                    {
                        g[k][i]-=g[r][i]*t;
                    }
                }
            }

            ++r;
            ++c;
        }

        for(int i=r;i<m;++i)
        {
            if(abs(g[i][n])>eps)
            {
                //printf("SOLVE\t1\n");
                return;
            }
        }

        for(int i=n-1;i>=0;--i)
        {
            x[i]=g[i][n];

            for(int j=i+1;j<n;++j)
            {
                x[i]-=x[j]*g[i][j];
            }

            x[i]/=g[i][i];

            if(x[i]<eps)
            {
                //printf("SOLVE\t\t2\n");
                return;
            }
        }

        double res=0;

        for(int i=0;i<n;++i)
        {
            res+=cst[i]*x[i];
        }

        //printf("RES\t%lf\n",res);
        ans=min(ans,res);
    }


    double mix(VI mixture, VS availableMixtures)
    {
        MSET(g,0);
        int i,j,k;
        ans=INF;

        int ct=availableMixtures.size();
        m=mixture.size();

        REP(i,m)
        {
            a[i]=mixture[i];
        }

        REP(i,ct)
        {
            istringstream sin(availableMixtures[i]);

            REP(j,m)
            {
                sin>>b[i][j];
            }
            sin>>p[i];
        }

        for(int st=1;st < 1<<ct;st++)
        {
            n=0;

            REP(i,ct)
            {
                if(st&(1<<i))
                {
                    ++n;
                }
            }

            REP(i,m)
            {
                g[i][n]=a[i];
            }

            j=0;

            REP(i,ct)
            {
                if(st&(1<<i))
                {
                    REP(k,m)
                    {
                        g[k][j]=b[i][k];
                    }

                    cst[j]=p[i];
                    ++j;
                }
            }

            solve();
        }

        if(ans==INF)
        {
            ans=-1;
        }


        return ans;
    }


};

int main()
{

    //freopen("Text/Mixture .txt","r",stdin);
    Mixture  ss;

    int a[]={1,2,3};

    string b[]={"1 0 0 1","0 1 0 2","0 0 1 3","2 2 2 4"};

    VI x;
    VS y;

    arrayToVectorInt(a,x,sizeof(a)/sizeof(*a));
    arrayToVectorString(b,y,sizeof(a)/sizeof(*b));

    printf("%lf\n",ss.mix(x,y));

	return 0;
}
