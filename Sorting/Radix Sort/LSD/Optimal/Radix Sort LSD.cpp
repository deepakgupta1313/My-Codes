#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>

using namespace std;

#define PB push_back

#define MAX_N 100

vector<int> vect[MAX_N];
vector<int> arr;

int n,mxlog,nlog;

void radix_sort_lsd()
{
    int i,j,k;
    int tn=pow(2,nlog);

    int base=tn;

    int rec=ceil(mxlog/nlog);

    for(i=0;i<=rec;++i)
    {

        for(k=0;k<n;++k)
        {
            vect[(arr[k]%tn)/(tn/base)].PB(arr[k]);
        }

        tn*=base;

        arr.clear();

        for(j=0;j<base;++j)
        {
            for(k=0;k<vect[j].size();++k)
            {
                arr.PB(vect[j][k]);
            }

            vect[j].clear();
        }


    }

    for(i=0;i<n;++i)
    {
        printf("%d\n",arr[i]);
    }

}



int main() {

    freopen("Radix Sort LSD.txt","r",stdin);
    int i,j,dum,mx=0;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        arr.PB(dum);
        if(dum>mx)
        {
            mx=dum;
        }
    }

    //cout<<mx<<endl;
    mxlog=ceil(log(mx));
    nlog=ceil(log(n));

    radix_sort_lsd();



	return 0;
}
