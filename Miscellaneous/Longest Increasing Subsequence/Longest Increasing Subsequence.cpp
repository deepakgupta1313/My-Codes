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

vector<int> vect,countt,pre;
int n;

void display(int pos)
{
    if(pre[pos]==pos)
    {
        printf("%d\n",vect[pos]);
        return;
    }

    display(pre[pos]);
    printf("%d\n",vect[pos]);
}

void longest_increasing_subsequence()
{
    int i,j,maxx=0,temp;

    for(i=0;i<n;++i)
    {
        countt[i]=1;
        pre[i]=i;
    }

    for(i=1;i<n;++i)
    {
        for(j=i-1;j>=0;--j)
        {
            if(vect[i]>vect[j])
            {
                temp=countt[j]+1;

                if(temp>=countt[i])
                {
                    countt[i]=temp;
                    pre[i]=j;
                    if(countt[i]>countt[maxx])
                    {
                        maxx=i;
                    }
                }
            }
        }
    }

    printf("Max Count\t%d\n\n",countt[maxx]);
    display(maxx);
}

int main()
{

    freopen("Longest Increasing Subsequence.txt","r",stdin);
    int i,j,temp;


    scanf("%d",&n);
    countt.resize(n);
    pre.resize(n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&temp);
        vect.PB(temp);
    }

    longest_increasing_subsequence();

	return 0;
}
