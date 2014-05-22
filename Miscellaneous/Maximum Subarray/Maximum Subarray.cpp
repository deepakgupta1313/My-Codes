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

vector<int> vect;
int n,mn=-1;
bool all_negative=true;

void maximum_subarray()
{
    printf("St\tEn\tSum\n");
    if(all_negative)
    {
        printf("%d\t%d\t%d\n",mn,mn,vect[mn]);
        return;
    }

    int i,j,gl_st,gl_en,st,en,gl_mx,mx;

    i=0;
    gl_mx=INT_MIN;
    mx=0;
    st=0;

    while(i<n)
    {
        mx+=vect[i];

        if(mx<=0)
        {
            mx=0;
            st=i+1;
        }
        else
        {
            if(mx>gl_mx)
            {
                gl_st=st;
                gl_en=i;
                gl_mx=mx;
            }
        }

        ++i;
    }

    printf("%d\t%d\t%d\n",gl_st,gl_en,gl_mx);

}

int main() {

    freopen("Maximum Subarray.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
        if(dum>0)
        {
            all_negative=false;
        }
        else if(mn==-1 || dum<vect[mn])
        {
            mn=i;
        }
    }

    maximum_subarray();

	return 0;
}
