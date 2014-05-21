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

void quicksort(int st,int en)
{
    int ran=en-st+1;
    if(ran<=1)
    {
        return;
    }

    int pivot=st+((rand())%ran);
    printf("%d\t%d\t%d\n",st,pivot,en);
    swap(en,pivot);

    int l=st,r=en-1;

    while(true)
    {
        while(l<=r && vect[l]<=vect[en])
        {
            ++l;
        }

        while(r>l && vect[r]>vect[en])
        {
            --r;
        }

        if(l<r)
        {
            swap(l,r);
            ++l;
            --r;
        }

        if(l>=r)
        {
            break;
        }
    }
    swap(l,en);

    quicksort(st,l-1);
    quicksort(l+1,en);

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

    freopen("Quicksort.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    quicksort(0,n-1);

    display();


	return 0;
}
