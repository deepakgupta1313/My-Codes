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

int bin_search(int st,int en,int num)
{
    if(st>en)
    {
        return -1;
    }

    int mid;

    while(st<en)
    {
        mid=st+(en-st+1)/2;
        if(vect[mid]<=num)
        {
            st=mid;
        }
        else
        {
            en=mid-1;
        }
    }

    if(vect[st]<=num)
    {
        return st;
    }
    else
    {
        return st-1;
    }
}

void insertion_sort()
{
    int i,j;
    int dum,pos;

    for(i=1;i<n;++i)
    {
        dum=vect[i];
        pos=bin_search(0,i-1,dum);

        for(j=i;j>pos+1;--j)
        {
            vect[j]=vect[j-1];
        }
        vect[pos+1]=dum;
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

    freopen("Insertion Sort.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    insertion_sort();

    display();


	return 0;
}
