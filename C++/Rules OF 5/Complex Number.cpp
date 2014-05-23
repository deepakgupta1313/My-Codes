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

class lst
{
    private :

        int sz;
        int *ls;

    public  :

        void setSize(int s)
        {
            sz=s;
            ls=new int[sz];
        }

        int getSize()
        {
            return sz;
        }

        lst(int s)
        {
            printf("Constructor\t%d\n",s);
            sz=s;
            ls=new int[sz];
        }

        lst(const lst &b)
        {
            printf("Copy Construct\t%d\n",b.sz);
            sz=b.sz;
            ls=new int[sz];

            int i;

            for(i=0;i<sz;++i)
            {
                ls[i]=b.ls[i];
            }
        }

        ~lst()
        {
            printf("Destructor\t%d\n",sz);
            delete[] ls;
        }

        lst operator=(const lst &b)
        {
            printf("Copy Assignment\t%d\n",b.sz);
            sz=b.sz;
            delete[] ls;
            ls=new int[sz];

            int i;

            for(i=0;i<sz;++i)
            {
                ls[i]=b.ls[i];
            }

            return *this;
        }


        lst& operator=(lst&& x)
        {
            printf("Move Assisgnment\t%d\n",x.sz);
            delete[] ls;
            sz=x.sz;
            ls=x.ls;
            x.ls=NULL;
            return *this;
        }

        lst(lst&& x)
        {
            printf("Move Constructor\t%d\n",x.sz);
            sz=x.sz;
            ls=x.ls;
            x.ls=NULL;
        }




};

lst getLst()
{
    lst ret=lst(3);
    return ret;
}

int main()
{
    lst a=lst(2);
    lst b=a;
    lst c=lst(1);
    c=b;
    //b=c;
    //a=getLst();

	return 0;
}
