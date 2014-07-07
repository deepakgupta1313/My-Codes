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

#define INF 999999

vector<int> a,en,pre;
int n;

void display(int pos)
{
    if(pos==-1)
    {
        return;
    }

    display(pre[pos]);

    printf("%d\t%d\n",pos,a[pos]);
}

int CeilIndex(int l, int r, int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (a[en[m]] >= key ? r : l) = m; // ternary expression returns an l-value
    }

    return r;
}

void longest_increasing_subsequence()
{
    int i,j,temp;
    en[0]=0;
    pre[0]=-1;

    int len=1;

    for(i=1;i<n;++i)
    {
        if(a[i]<a[en[0]])
        {
            en[0]=i;
            pre[i]=-1;
        }
        else if(a[i]>a[en[len-1]])
        {
            en[len]=i;
            pre[i]=en[len-1];
            ++len;
        }
        else
        {
            temp=CeilIndex(-1,len-1,a[i]);
            pre[i]=en[temp-1];
            en[temp]=i;
        }
    }

    //printf("Max Count\t%d\n\n",len);
    printf("%d\n",len);
    //display(en[len-1]);

}

int main()
{

    freopen("Longest Increasing Subsequence.txt","r",stdin);
    int i,j,temp;


    scanf("%d",&n);
    en.resize(n);
    pre.resize(n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&temp);
        a.PB(temp);
        en[i]=0;
    }

    longest_increasing_subsequence();

	return 0;
}
