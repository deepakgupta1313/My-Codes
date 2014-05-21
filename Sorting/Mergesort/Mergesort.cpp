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

void mergesort(int st,int en)
{
    int ran=en-st+1;

    if(ran<=1)
    {
        return;
    }

    int mid=st+(en-st)/2;
    mergesort(st,mid);
    mergesort(mid+1,en);

    int arr[ran];
    int i=0,j=0;
    int l1=mid-st+1;
    int l2=en-mid;
    int k=0;

    while(i<l1 && j<l2)
    {
        if(vect[st+i]<vect[mid+1+j])
        {
            arr[k++]=vect[st+i];
            ++i;
        }
        else
        {
            arr[k++]=vect[mid+1+j];
            ++j;
        }
    }

    while(i<l1)
    {
        arr[k++]=vect[st+i];
        ++i;
    }

    while(j<l2)
    {
        arr[k++]=vect[mid+1+j];
        ++j;
    }

    for(k=0;k<ran;++k)
    {
        vect[st+k]=arr[k];
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

    freopen("Mergesort.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    mergesort(0,n-1);

    display();


	return 0;
}
