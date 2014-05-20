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
#define pb push_back

vector<int> main_vector;
int n;

int linear_search(int num)
{
    int i;
    for(i=0;i<n;++i)
    {
        if(main_vector[i]==num)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    freopen("Linear_Search.txt","r",stdin);


    int i,j,temp;

    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&temp);
        main_vector.pb(temp);
    }

    printf("Input\n\n");
    printf("%d\n",n);
    for(i=0;i<n;++i)
    {
        printf("%d\t",main_vector[i]);
    }
    printf("\n\n\n");

    printf("Searches\n");
    printf("7\t%d\n",linear_search(7));

    return 0;
}
