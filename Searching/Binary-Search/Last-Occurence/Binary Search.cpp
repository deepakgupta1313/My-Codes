#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define i64 long long
#define pb push_back

vector<int> vect;
int n;

int binary_search_last(int num)
{
    int mid,st=0,en=n-1;

    while(st<en)
    {
        mid=st+(en-st+1)/2;

        if(vect[mid]>num)
        {
            en=mid-1;
        }
        else if(vect[mid]==num)
        {
            st=mid;
        }
        else
        {
            st=mid+1;
        }
    }

    if(vect[st]==num)
    {
        return st;
    }

    return -1;
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

    printf("1\t%d\n",binary_search_last(1));
    printf("2\t%d\n",binary_search_last(2));
    printf("3\t%d\n",binary_search_last(3));
    printf("5\t%d\n",binary_search_last(5));

}
