#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

#define i64 long long
#define pb push_back

vector<int> vect;
int n;

int binary_search_2(int num)
{
    int i=ceil(n/2.0),m=floor(n/2.0);;

    while(true)
    {
        if(vect[i-1]>num)
        {
            if(m==0)
            {
                return -1;
            }
            i-=ceil(m/2.0);
            m=floor(m/2.0);
        }
        else if(vect[i-1]==num)
        {
            return i-1;
        }
        else
        {
            if(m==0)
            {
                return -1;
            }
            i+=ceil(m/2.0);
            m=floor(m/2.0);
        }
    }

}

int main()
{
    freopen("Binary_Search.txt","r",stdin);

    int i,j,temp;

    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&temp);
        vect.pb(temp);
    }

    printf("Input\n\n");
    printf("%d\n",n);

    for(i=0;i<n;++i)
    {
        printf("%d\t",vect[i]);
    }
    printf("\n\n\n");


    printf("Searches\n");

    printf("1\t%d\n",binary_search_2(1));
    printf("2\t%d\n",binary_search_2(2));
    printf("3\t%d\n",binary_search_2(3));
    printf("5\t%d\n",binary_search_2(5));

}
