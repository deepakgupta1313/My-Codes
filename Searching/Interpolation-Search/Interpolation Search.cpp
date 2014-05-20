#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define i64 long long
#define pb push_back

vector<int> vect;
int n;

int interpolation_search(int num)
{
    int mid,st=0,en=n-1;

    while(st<en && vect[st]<=num && vect[en]>=num)
    {
        mid=st+(num-vect[st])*(en-st)/(vect[en]-vect[st]);

        if(vect[mid]<num)
        {
            st=mid+1;
        }
        else if(vect[mid]>num)
        {
            en=mid-1;
        }
        else
        {
            return mid;
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
    freopen("Interpolation Search.txt","r",stdin);

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

    printf("88\t%d\n",interpolation_search(88));
    printf("95\t%d\n",interpolation_search(95));
    printf("100\t%d\n",interpolation_search(100));
    printf("101\t%d\n",interpolation_search(101));

}
