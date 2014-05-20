//      Unimodal Function
//      Finds Max
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define i64 long long
#define pb push_back
#define pii pair<int,int>
#define vpii vector< pii >

int n;
vector<int> vect;

int ternary_search()
{
    int l=0,r=n-1,m1,m2,tt;

    while(l<r)
    {

        tt=(r-l)/3;
        m1=l+tt;
        m2=r-tt;

        //printf("%d %d\n",m1,m2);

        if(vect[m1]<vect[m2])
        {
            l=m1+1;
        }
        else
        {
            r=m2-1;
        }
    }

    return l;
}

int main()
{
    freopen("Ternary Search.txt","r",stdin);
    int i,j,temp;


    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&temp);
        vect.pb(temp);
    }

    printf("Position Of Maximum Value\t%d\n",ternary_search());


    return 0;
}

