#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define PB push_back

vector<int> vect;
int n,tn;

void swap(int a,int b)
{
    int dum=vect[a];
    vect[a]=vect[b];
    vect[b]=dum;
}

void heapify()
{
    int dn=n-1,par;
    if(!(n&1))
    {
        if(vect[n-1]<vect[(n-1)>>1])
        {
            swap(n-1,(n-1)>>1);
        }
        dn-=2;
    }
    else
    {
        --dn;
    }

    while(dn>=1)
    {
        par=dn>>1;
        if(vect[dn]<=vect[dn+1] && vect[dn]<vect[par])
        {
            swap(dn,par);
        }
        else if(vect[dn]>=vect[dn+1] && vect[dn+1]<vect[par])
        {
            swap(dn+1,par);
        }
        dn-=2;
    }

}

void bubble_down(int idx)
{
    int l,r;
    while(true)
    {
        l=2*idx+1;
        r=l+1;

        if(l>=tn && r>=tn)
        {
            break;
        }

        if(r>=tn)
        {
            if(vect[l]<vect[idx])
            {
                swap(l,idx);
            }
            break;
        }
        else
        {
            if(vect[l]<=vect[r] && vect[idx]>vect[l])
            {
                swap(l,idx);
                idx=l;
            }
            else if(vect[l]>=vect[r] && vect[idx]>vect[r])
            {
                swap(idx,r);
                idx=r;
            }
            else
            {
                break;
            }
        }
    }
}


int delete_min()
{
    int ret=vect[0];

    vect[0]=vect[tn-1];
    --tn;
    bubble_down(0);

    return ret;
}

void heap_sort()
{
    int i,j;

    heapify();
    tn=n;

    for(i=0;i<n;++i)
    {
        printf("%d\n",delete_min());
    }
}



int main() {

    freopen("Heap Sort.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    heap_sort();


	return 0;
}
