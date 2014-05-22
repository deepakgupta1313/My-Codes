#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define PB push_back

vector<int> vect;
int n,mxlen;

vector<int> rad[10];

void swap(int a,int b)
{
    int dum=vect[a];
    vect[a]=vect[b];
    vect[b]=dum;
}

void radix_sort_lsd()
{
    int i,j,k;
    int tn=10;

    for(i=0;i<mxlen;++i)
    {
        for(j=0;j<n;++j)
        {
            rad[(vect[j]%tn)/(tn/10)].PB(vect[j]);
        }

        vect.clear();

        for(j=0;j<10;++j)
        {
            for(k=0;k<rad[j].size();++k)
            {
                vect.PB(rad[j][k]);
            }
            rad[j].clear();
        }

        tn*=10;


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

void calc_mx_len(int num)
{

    if(num==0)
    {
        mxlen=1;
        return;
    }
    mxlen=0;

    while(num!=0)
    {
        ++mxlen;
        num/=10;
    }
}

int main() {

    freopen("Radix Sort LSD.txt","r",stdin);
    int i,j,dum,mx=0;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
        if(dum>mx)
        {
            mx=dum;
        }
    }

    calc_mx_len(mx);

    radix_sort_lsd();

    display();


	return 0;
}
