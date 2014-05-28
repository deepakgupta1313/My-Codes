#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define PB push_back

vector<int> vect;
vector<int> used;
int n;


void display()
{
    int i;

    for(i=0;i<n;++i)
    {
        printf("%d\t",used[i]);
    }
    printf("\n");
}


void swap(int a,int b)
{
    int dum=used[a];
    used[a]=used[b];
    used[b]=dum;
}

int quicksearch(int p,int q,int pos)
{
    int rang,pivot,tp,tq,i,j;

    while(p<=q)
    {

        if(p==q)
        {
            return used[p];
        }
        tp=p;
        tq=q;

        rang=q-p+1;
        pivot=(rand()%rang)+p;

        swap(pivot,tq);

        --tq;

        while(true)
        {
            while(tp<=tq && used[tp]<used[q])
            {
                ++tp;
            }

            while(tp<tq && used[tq]>=used[q])
            {
                --tq;
            }

            if(tp<tq)
            {
                swap(tp,tq);
                ++tp;
                --tq;
            }
            else
            {
                break;
            }
        }

        swap(tp,q);

        if(tp==pos)
        {
            return used[pos];
        }
        else if(tp<pos)
        {
            p=tp+1;
        }
        else
        {
            q=tp-1;
        }


    }

}



int main() {

    freopen("Quick Search.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    for(i=0;i<n;++i)
    {
        used.clear();
        for(j=0;j<n;++j)
        {
            used.PB(vect[j]);
        }
        printf("%d\t%d\n",i,quicksearch(0,n-1,i));
        display();
    }

	return 0;
}
