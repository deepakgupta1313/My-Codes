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

void bubble_sort()
{
    int i,j;
    int mx=0;

    for(i=0;i<n-1;++i)
    {
        for(j=1;j<n-i;++j)
        {
            if(vect[j]<vect[j-1])
            {
                swap(j,j-1);
            }
        }
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

    freopen("Bubble Sort.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    bubble_sort();

    display();


	return 0;
}
