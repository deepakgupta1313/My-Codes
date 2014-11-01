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

#define INF 999999999
#define MAXN 51
#define MAXMN ( MAXN*MAXN*4 + MAXN*7 )
#define MAXNN ( MAXN*7 )

int n,cell;

int upp[MAXMN],downn[MAXMN],leftt[MAXMN],rightt[MAXMN],headd[MAXMN],columnn[MAXMN],roww[MAXMN];
int ans[MAXNN],ct[MAXNN],x[MAXNN],y[MAXNN],rarr[MAXNN],coveredd[MAXNN];


int cmp(const void *p,const void *q)
{
    int *a=(int *)p;
    int *b=(int *)q;
    return x[*a]-x[*b];
}

void clearr(int num_rows,int num_cols)
{
    for(int i=0;i<=num_cols;++i)
    {
        ct[i]=0;
        upp[i]=downn[i]=i;
        leftt[i+1]=i;
        rightt[i]=i+1;
    }
    rightt[num_cols]=0;
    cell=num_cols;

    for(int i=1;i<=num_rows;++i)
    {
        headd[i]=-1;
    }

    MSET(coveredd,0);
}

void place(int &r,int &col1,int &col2,int &col3,int &col4,int i,int j)
{
    r=(i-1)*n+j;
    col1=j;
    col2=n+i;
    col3=n*3+i-j;
    col4=n*4+i+j-2;
}

void joinn(int r,int head_col)
{
    ++cell;
    columnn[cell]=head_col;
    ++ct[head_col];
    roww[cell]=r;
    downn[cell]=downn[head_col];
    upp[downn[head_col]]=cell;
    upp[cell]=head_col;
    downn[head_col]=cell;

    if(headd[r]<0)
    {
        headd[r]=leftt[cell]=rightt[cell]=cell;
    }
    else
    {
        rightt[cell]=rightt[headd[r]];
        leftt[rightt[headd[r]]]=cell;
        leftt[cell]=headd[r];
        rightt[headd[r]]=cell;
    }
}


void init()
{
    int r,col1,col2,col3,col4;

    clearr(n*n,n*6-2);
    int j;


    for(int i=1;i<=n;++i)
    {
        scanf("%d",&j);
        //printf("J\t%d\n",j);
        if(j)
        {
            place(r,col1,col2,col3,col4,i,j);
            joinn(r,col1);
            joinn(r,col2);
            joinn(r,col3);
            joinn(r,col4);

            coveredd[col1]=coveredd[col2]=coveredd[col3]=coveredd[col4]=1;
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            place(r,col1,col2,col3,col4,i,j);

            if(coveredd[col1]|| coveredd[col2] || coveredd[col3] || coveredd[col4])
            {
                continue;
            }

            joinn(r,col1);
            joinn(r,col2);
            joinn(r,col3);
            joinn(r,col4);

        }
    }
}

void coverr(int headd_col)
{
    leftt[rightt[headd_col]]=leftt[headd_col];
    rightt[leftt[headd_col]]=rightt[headd_col];

    for(int i=downn[headd_col];i!=headd_col;i=downn[i])
    {
        for(int j=rightt[i];j!=i;j=rightt[j])
        {
            upp[downn[j]]=upp[j];
            downn[upp[j]]=downn[j];
            --ct[columnn[j]];
        }
    }
}

void uncoverr(int headd_col)
{
    leftt[rightt[headd_col]]=headd_col;
    rightt[leftt[headd_col]]=headd_col;

    for(int i=downn[headd_col];i!=headd_col;i=downn[i])
    {
        for(int j=rightt[i];j!=i;j=rightt[j])
        {
            ++ct[columnn[j]];
            upp[downn[j]]=j;
            downn[upp[j]]=j;
        }
    }


}


bool dance(int curr)
{
    if(curr>=n)
    {
        for(int i=0;i<curr;++i)
        {
            x[i]=(roww[ans[i]]-1)/n+1;
            y[i]=(roww[ans[i]]-1)%n +1;
        }

        return 1;
    }

    if(!rightt[0])
    {
        return 0;
    }

    int ti=INF;
    int nxt_col;

    for(int i=rightt[0];i<=n;i=rightt[i])
    {
        if(ct[i]<ti)
        {
            ti=ct[i];
            nxt_col=i;
        }
    }

    coverr(nxt_col);

    for(int i=downn[nxt_col];i!=nxt_col && i;i=downn[i])
    {
        ans[curr]=i;

        for(int j=rightt[i];j!=i;j=rightt[j])
        {
            coverr(columnn[j]);
        }

        if(dance(curr+1))
        {
            return 1;
        }

        for(int j=leftt[i];j!=i;j=leftt[j])
        {
            uncoverr(columnn[j]);
        }
    }

    uncoverr(nxt_col);

    return 0;

}

void print_ans()
{
    for(int i=0;i<n;++i)
    {
        rarr[i]=i;
    }

    //sort(rarr,rarr+n,cmp);
    qsort(rarr,n,sizeof(rarr[0]),cmp);

    for(int i=0;i<n;++i)
    {
        if(i)
        {
            printf(" ");
        }

        printf("%d",y[rarr[i]]);
    }
    printf("\n");
}


int main()
{
    freopen("Text/NQUEEN.txt","r",stdin);

    while(scanf("%d",&n)!=EOF)
    {
        //printf("%d\n",n);
        init();
        if(dance(0))
        {
            print_ans();
        }
    }


    return 0;
}
