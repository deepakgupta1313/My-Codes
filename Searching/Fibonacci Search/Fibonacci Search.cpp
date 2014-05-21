#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define i64 long long
#define pb push_back
#define pii pair<int,int>
#define vpii vector< pii >

int n,temp,one, two;
vector<int> vect;

int fibonacci_search(int num)
{
    int st=0,en=n-1;

    one=1;
    two=1;

    while(two<=en)
    {
        temp=two;
        two=one+two;
        one=temp;
    }

    while(two>1)
    {
        printf("%d\t%d\t%d\n",st,one,two);
        if(st+one-1>en || vect[st+one-1]>num)
        {
            temp=two-one;
            two=one;
            one=temp;
        }
        else if(vect[st+one-1]<num)
        {
            st+=one;
            temp=two-one;
            one=one-temp;
            two=temp;
        }
        else
        {
            return st+one-1;
        }
    }

    if(one==1)
    {
        if(st<=en && vect[st]==num)
        {
            return st;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

}

int main()
{
    freopen("Fibonacci Search.txt","r",stdin);
    int i,j;


    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&temp);
        vect.pb(temp);
    }

    printf("%d\n",fibonacci_search(4));


    return 0;
}

