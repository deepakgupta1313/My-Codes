#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define PB push_back

void fibonacci(int n)
{
    printf("The first %d fibonacci numbers are :\n",n);
    if(n>=1)
    {
        printf("0\n");
    }

    if(n>=2)
    {
        printf("1\n");
    }

    if(n>2)
    {
        int tt;
        int pre=0,next=1;
        int i=3;

        while(i<=n)
        {
            ++i;
            tt=next;
            next+=pre;
            pre=tt;
            printf("%d\n",next);
        }

    }
}

int main() {

    freopen("Fibonacci.txt","r",stdin);
    int i,j,cases,n,m;

    scanf("%d",&n);

    fibonacci(n);


	return 0;
}
