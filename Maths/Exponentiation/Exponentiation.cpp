#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define PB push_back

int poww(int n,int m)
{
    int ret=1;

    while(m>0)
    {
        if(m&1)
        {
            ret*=n;
        }
        n*=n;
        m/=2;
    }

    return ret;
}

int main() {

    freopen("Exponentiation.txt","r",stdin);
    int i,j,cases,n,m;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&n,&m);
        printf("%d raised to %d is %d\n\n",n,m,poww(n,m));
    }


	return 0;
}
