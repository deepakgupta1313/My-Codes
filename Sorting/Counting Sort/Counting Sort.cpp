#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

#define PB push_back

#define MAXN 100


vector<int> vect;
int n;
int a[MAXN];

void counting_sort()
{
    int i,j;
    memset(a,0,sizeof(a));

    for(i=0;i<n;++i)
    {
        ++a[vect[i]];
    }
}

void display()
{
    int i,j;

    for(i=0;i<MAXN;++i)
    {
        for(j=0;j<a[i];++j)
        {
            printf("%d\n",i);
        }
    }
}

int main() {

    freopen("Counting Sort.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    counting_sort();

    display();


	return 0;
}
