#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define PB push_back

vector<int> vect;
int n;

void swap(int a,int b)
{
    int dum=vect[a];
    vect[a]=vect[b];
    vect[b]=dum;
}

void selection_sort()
{
    int i,j;
    int mx=0;

    for(i=1;i<n;++i)
    {
        mx=0;
        for(j=1;j<=n-i;++j)
        {
            if(vect[j]>vect[mx])
            {
                mx=j;
            }
        }
        swap(mx,n-i);
    }
}

void display()
{
    int i;

    for(i=0;i<n;++i)
    {
        printf("%d\n",vect[i]);
    }
}

int main() {

    freopen("Selection Sort.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    selection_sort();

    display();


	return 0;
}
