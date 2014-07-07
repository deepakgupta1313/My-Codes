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

#define MAXL 1000

int matr[MAXL+1][MAXL+1];
int prex[MAXL+1][MAXL+1];
int prey[MAXL+1][MAXL+1];
bool included[MAXL+1][MAXL+1];

string gla,glb;

void pr_ans(int x,int y)
{
    if(prex[x][y]!=0)
    {
        pr_ans(prex[x][y],prey[x][y]);
    }

    if(included[x][y])
    {
        printf("%d\t%d\t%c\n",x,y,gla[x-1]);
    }
}

void lcs(string a,string b)
{
    gla=a;
    glb=b;

    MSET(prex,0);
    MSET(prey,0);
    MSET(included,0);

    int al=a.length();
    int bl=b.length();

    int i,j;

    for(i=0;i<=al;++i)
    {
        for(j=0;j<=bl;++j)
        {
            if(i==0 || j==0)
            {
                matr[i][j]=0;
            }
            else
            {
                if(matr[i-1][j]>matr[i][j-1])
                {
                    matr[i][j]=matr[i-1][j];
                    prex[i][j]=i-1;
                    prey[i][j]=j;
                }
                else
                {
                    matr[i][j]=matr[i][j-1];
                    prex[i][j]=i;
                    prey[i][j]=j-1;
                }

                if(a[i-1]==b[j-1])
                {
                    if(matr[i][j]< (matr[i-1][j-1]+1))
                    {
                        matr[i][j]=matr[i-1][j-1]+1;
                        included[i][j]=true;
                        prex[i][j]=i-1;
                        prey[i][j]=j-1;
                    }
                }
            }
        }
    }

    printf("%d\n",matr[al][bl]);

    pr_ans(al,bl);
    printf("\n");

}

int main()
{
    string a="quetzalcoatl";
    string b="ezaloa";

    lcs(a,b);

	return 0;
}
