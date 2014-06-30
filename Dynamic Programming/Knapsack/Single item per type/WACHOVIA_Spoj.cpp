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

#define MAXK 1000
#define MAXM 50

int dp[MAXM+1][MAXK+1];
int weights[MAXM+1];
int costs[MAXM+1];
int m,k;

int main()
{

    freopen("WACHOVIA_Spoj.txt","r",stdin);
    int i,j,x,y,cases;

    scanf("%d",&cases);

    while(cases--)
    {
        MSET(dp,0);
        scanf("%d %d",&k,&m);

        REP(i,m)
        {
            scanf("%d %d",weights+i,costs+i);
        }

        REP(i,m)
        {
            for(j=1;j<=k;++j)
            {
                if(weights[i]>j)
                {
                    dp[i+1][j]=dp[i][j];
                }
                else
                {
                    dp[i+1][j]=max(dp[i][j],costs[i]+dp[i][j-weights[i]]);
                }
            }
        }

        printf("Hey stupid robber, you can get %d.\n",dp[m][k]);
    }

	return 0;
}
