#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <climits>

#define i64 long long

using namespace std;

int n,e,t;
long ad[100][100];

long minn(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

int main()
{
	//freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/MICEMAZE.txt","r",stdin);
	freopen("MICEMAZE_Spoj.txt","r",stdin);
    int i=0,j=0,k;
    int m,a,b,d;

    scanf("%d",&n);
    scanf("%d",&e);
    --e;
    scanf("%d",&t);
    scanf("%d",&m);
    //memset(ad,-1,sizeof(ad));



    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            ad[i][j]=1000;
        }
    }

    for(i=0;i<n;++i)
    {
        ad[i][i]=0;
    }

    while(m--)
    {
        scanf("%d %d %d",&a,&b,&d);
        --a;
        --b;
        ad[b][a]=d;
    }



    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            for(k=0;k<n;++k)
            {
                ad[i][j]=minn(ad[i][j],ad[i][k]+ad[k][j]);
            }
        }
    }
    int count=0;
    for(i=0;i<n;++i)
    {
        if(ad[e][i]<=t)
        {
            //cout<<i<<endl;
            ++count;
        }
    }

    printf("%d\n",count);



    return 0;
}



