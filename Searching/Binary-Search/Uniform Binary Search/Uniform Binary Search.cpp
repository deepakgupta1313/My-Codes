#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

#define i64 long long
#define pb push_back

vector<int> vect;
int n;
#define LOG_N 42
static int delta[LOG_N];


int binary_search_uniform(int num)
{
    int i=delta[0]-1;
    int d=0;

    while(true)
    {
        if(num==vect[i])
        {
            return i;
        }
        else if(delta[d]==0)
        {
            return -1;
        }
        else
        {
            if(num<vect[i])
            {
                i-=delta[++d];
            }
            else
            {
                i+=delta[++d];
            }
        }
    }

}

void preprocess(int num)
{
    int one,two=1,i=0;

    do
    {
        one=two;
        two<<=1;
        delta[i]=(num+one)/two;
    }
    while(delta[i++]!=0);
}

int main()
{
    freopen("Uniform Binary Search.txt","r",stdin);

    int i,j,temp;

    scanf("%d",&n);

    preprocess(n);

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

    printf("1\t%d\n",binary_search_uniform(1));
    printf("2\t%d\n",binary_search_uniform(2));
    printf("3\t%d\n",binary_search_uniform(3));
    printf("5\t%d\n",binary_search_uniform(5));

}
