#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define PB push_back

vector<int> vect;

void display(vector<int> a)
{
    for(int i=0;i<a.size();++i)
    {
        printf("%d\t",a[i]);
    }

    printf("\n\n");
}



void swapp(int &a,int &b)
{
    int tp=a;
    a=b;
    b=tp;
}

int sortt(vector<int> &a,vector<int> &b,int st,int en)
{
    int i,j,tp;
    int n=en-st+1;

    for(i=0;i<n-1;++i)
    {
        for(j=1;j<n-i;++j)
        {
            if(b[j+st]<b[j+st-1])
            {
                tp=b[j+st];
                b[j+st]=b[j+st-1];
                b[j+st-1]=tp;

                tp=a[j+st];
                a[j+st]=a[j+st-1];
                a[j+st-1]=tp;
            }
        }
    }

    return (st+n/2);
}




int quicksearch(int n,int pos,vector<int> &a,vector<int> &b)
{
    int pivot,tp,tq,i,j;

    if(n<=5)
    {
        sortt(a,b,0,n-1);
        return a[pos];
    }

    vector<int> x,y;

    for(i=0;i<ceil(n/5);++i)
    {
        x.PB(sortt(a,b,i*5,min((i+1)*5-1,n-1)));
        y.PB(b[i*5+min(2,(n-1-i*5+1)/2)]);
    }

    pivot=quicksearch(x.size(),x.size()/2,x,y);

    swapp(a[pivot],a[n-1]);
    swapp(b[pivot],b[n-1]);
    tp=0;
    tq=n-2;

    while(tp<=tq)
    {
        while(tp<=tq && b[tp]<b[n-1])
        {
            ++tp;
        }

        while(tp<tq && b[tq]>=b[n-1])
        {
            --tq;
        }

        if(tp<tq)
        {
            swapp(a[tp],a[tq]);
            swapp(b[tp],b[tq]);
        }
        else
        {
            break;
        }
    }

        swapp(a[tp],a[n-1]);
        swapp(b[tp],b[n-1]);

        if(tp==pos)
        {
            return a[pos];
        }
        else if(tp<pos)
        {
            x.clear();
            y.clear();
            for(i=tp+1;i<n;++i)
            {
                x.PB(a[i]);
                y.PB(b[i]);
            }

            return quicksearch(n-tp-1,pos-tp-1,x,y);
        }
        else
        {
            x.clear();
            y.clear();
            for(i=0;i<tp;++i)
            {
                x.PB(a[i]);
                y.PB(b[i]);
            }

            return quicksearch(tp,pos,x,y);
        }

}



int main() {

    freopen("Quick Search.txt","r",stdin);
    int i,j,dum,n;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    vector<int> a,b;

    for(i=0;i<n;++i)
    {
        a.clear();
        b.clear();

        for(j=0;j<n;++j)
        {
            a.PB(j);
            b.PB(vect[j]);
        }
        printf("%d\t%d\n",i,vect[quicksearch(n,i,a,b)]);
        sort(b.begin(),b.end());
        display(b);
    }

	return 0;
}
