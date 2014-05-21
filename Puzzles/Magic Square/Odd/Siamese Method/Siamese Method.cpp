#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <set>
#include <queue>

using namespace std;

#define i64 long long
#define MAXN 100

int a[MAXN][MAXN];
int summ;

void verify(int n)
{
    bool val=true;
    int sum1=0,sum2=0,i,j,sum3=0,sum4=0;

    for(i=0;i<n;++i)
    {
        sum1=0;
        sum2=0;
        sum3+=a[i][i];
        sum4+=a[i][n-1-i];
        for(j=0;j<n;++j)
        {
            sum1+=a[i][j];
            sum2+=a[j][i];
        }

        if(sum1!=summ || sum2!=summ)
        {
            val=false;
            break;
        }
    }

    if(val)
    {
        if(sum3!=summ || sum4!=summ)
        {
            val=false;
        }
    }

    if(val)
    {
        printf("Valid\n\n\n");
    }
    else
    {
        printf("Invalid\n\n\n");
    }
}

void siamese(int n)
{
    memset(a,0,sizeof(a));
    int x,y;

    if(!(n&1))
    {
        printf("Siamese Method is only for ODD Dimensions\n\n\n");
        return;
    }

    summ=n*(n*n+1)/2;

    int i=1,j;
    x=0;
    y=n/2;
    a[x][y]=i;

    while(i<n*n)
    {
        ++i;
        printf("%d\t%d\n",x,y);
        if( (x-1<0 && y+1>=n))
        {
            ++x;
            a[x][y]=i;
        }
        else if(x-1<0 || y+1>=n)
        {
            --x;
            if(x<0)
            {
                x+=n;
            }
            else
            {
                x%=n;
            }
            y=(y+1)%n;
            a[x][y]=i;
        }
        else if(a[x-1][y+1]!=0)
        {
            ++x;
            a[x][y]=i;
        }
        else
        {
            --x;
            ++y;
            a[x][y]=i;
        }
    }

    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    verify(n);
}

int main()
{
    siamese(3);
    siamese(9);
    siamese(99);

    return 0;
}
