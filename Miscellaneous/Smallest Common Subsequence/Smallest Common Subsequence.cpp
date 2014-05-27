#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>

using namespace std;

#define PB push_back

#define MAXLEN 20


struct link_t
{
    int len;
    char c;
    link_t *next;

    link_t()
    {

    }

    link_t(int p,char q,link_t *r)
    {
        len=p;
        c=q;
        next=r;
    }
};

char a[MAXLEN],b[MAXLEN];

link_t mat[MAXLEN+1][MAXLEN+1];


void smallest_common_subsequence()
{
    int la=strlen(a);
    int lb=strlen(b);
    int i,j;

    for(i=0;i<la;++i)
    {
        mat[lb][i]=link_t(la-i,a[i],&mat[lb][i+1]);
    }

    for(j=0;j<lb;++j)
    {
        mat[j][la]=link_t(lb-j,b[j],&mat[j+1][la]);
    }

    //mat[lb][la]=link_t(0);
    link_t *tp;

    for(i=lb-1;i>=0;--i)
    {
        for(j=la-1;j>=0;--j)
        {
            tp=&mat[i][j];
            if(b[i]==a[j])
            {
                tp->next=&mat[i+1][j+1];
                tp->c=a[j];
            }
            else if(mat[i][j+1].len<mat[i+1][j].len)
            {
                tp->next=&mat[i][j+1];
                tp->c=a[j];
            }
            else
            {
                tp->next=&mat[i+1][j];
                tp->c=b[i];
            }
            tp->len=tp->next->len+1;
        }
    }

    for(tp=&mat[0][0];tp;tp=tp->next)
    {
        printf("%c",tp->c);
    }

    printf("\n");

}

int main()
{

    freopen("Smallest Common Subsequence.txt","r",stdin);
    int i,j,temp;

    scanf("%s",a);
    scanf("%s",b);

    smallest_common_subsequence();

	return 0;
}
