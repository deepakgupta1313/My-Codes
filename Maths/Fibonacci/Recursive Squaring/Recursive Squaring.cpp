#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define PB push_back

void mull(int a[2][2],int b[][2])
{
    int ret[2][2]={0,0,0,0};

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                ret[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            b[i][j]=ret[i][j];
        }
    }
}

void fibonacci(int n)
{
    int ret[2][2]={1,0,0,1};

    if(n==2)
    {
        ret[0][1]=1;
    }
    if(n>2)
    {
        --n;
        int mat[2][2]={1,1,1,0};

        while(n>0)
        {
            if(n&1)
            {
                mull(mat,ret);
            }
            mull(mat,mat);
            n/=2;
        }

    }

    printf("The %d fibonacci number is :%d\n",n,ret[0][1]);
}

int main() {

    freopen("Recursive Squaring.txt","r",stdin);
    int i,j,cases,n,m;

    scanf("%d",&n);

    fibonacci(n);


	return 0;
}
