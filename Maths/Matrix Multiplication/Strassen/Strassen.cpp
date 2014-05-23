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

struct matrix
{
    private:

    int dimension;
    int *data;

    public  :

    matrix(int d)
    {
        dimension=d;
        data=new int[dimension*dimension];
    }

    matrix(int *mat,int d)
    {
        dimension=d;
        data=new int(dimension*dimension);

        int i;

        for(i=0;i<d*d;++i)
        {
            data[i]=mat[i];
        }
    }

    matrix(matrix *mat)
    {
        dimension=mat->dimension;
        data=new int(dimension*dimension);

        int i;

        for(i=0;i<dimension*dimension;++i)
        {
            data[i]=mat->data[i];
        }
    }

    matrix(const matrix &mat)
    {
        dimension=mat.dimension;
        data=new int[dimension*dimension];

        int i,j;

        for(i=0;i<dimension;++i)
        {
            for(j=0;j<dimension;++j)
            {
                //int num=b.get(i,j);
                sett(i,j,mat.data[i*dimension+j]);
                //this->sett(i,j,b.get(i,j));
            }
        }
    }

    matrix operator+(const matrix &mat)
    {
        matrix ret(dimension);

        int i;

        for(i=0;i<dimension*dimension;++i)
        {
            ret.data[i]=data[i]+mat.data[i];
        }

        return ret;
    }

    matrix operator=(const matrix &b)
    {
        int i,j;

        for(i=0;i<dimension;++i)
        {
            for(j=0;j<dimension;++j)
            {
                //int num=b.get(i,j);
                sett(i,j,b.data[i*dimension+j]);
                //this->sett(i,j,b.get(i,j));
            }
        }

        return *this;
    }


    int get(int x,int y)
    {
        return data[x*dimension+y];
    }

    int sett(int x,int y,int val)
    {
        data[x*dimension+y]=val;
    }

    int getDimension()
    {
        return dimension;
    }

    void setDimension(int d)
    {
        dimension=d;
    }

    friend ostream &operator<<(ostream &out,matrix mat)
    {
        int i,j;

        for(i=0;i<mat.getDimension();++i)
        {
            for(j=0;j<mat.getDimension();++j)
            {
                printf("%d\t",mat.get(i,j));
            }
            printf("\n");
        }

        printf("\n");
        printf("\n");

        return out;
    }
};


void printMatrix(matrix mat)
{
    int i,j;

    for(i=0;i<mat.getDimension();++i)
    {
        for(j=0;j<mat.getDimension();++j)
        {
            printf("%d\t",mat.get(i,j));
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
}


int main()
{

    freopen("Strassen.txt","r",stdin);
    int i,j,dim,num;

    scanf("%d",&dim);

    matrix *a=new matrix(dim);
    matrix *b=new matrix(dim);

    for(i=0;i<dim;++i)
    {
        for(j=0;j<dim;++j)
        {
            scanf("%d",&num);
            a->sett(i,j,num);
            //printf("%d\t",num);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    for(i=0;i<dim;++i)
    {
        for(j=0;j<dim;++j)
        {
            scanf("%d",&num);
            b->sett(i,j,num);
            //printf("%d\t",num);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    cout<<*a<<*b;

    matrix *c=new matrix(dim);

	return 0;
}
