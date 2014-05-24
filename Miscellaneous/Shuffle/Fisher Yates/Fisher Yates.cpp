#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>

using namespace std;

#define PB push_back

void fisher_yates(int num)
{
    printf("Fisher Yates\t%d\n",num);
    int i,j,k;
    int a[num];

    for(i=0;i<num;++i)
    {
        a[i]=i;
    }

    for(i=num;i>0;--i)
    {
        j=rand()%i;
        k=a[j];
        a[j]=a[i-1];
        a[i-1]=k;
    }

    for(i=0;i<num;++i)
    {
        printf("%d\n",a[i]);
    }

    printf("\n\n");
}

int main()
{

    freopen("Matrix Multiplication.txt","r",stdin);
    int i,j;

    fisher_yates(10);
    fisher_yates(10);
    fisher_yates(10);

	return 0;
}
