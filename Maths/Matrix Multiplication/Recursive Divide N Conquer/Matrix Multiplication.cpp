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


void add1(matrix *c,matrix *a,matrix *b,int x,int y)
{
    int dim=a->getDimension();

    int i,j,summ;

    for(i=0;i<dim;++i)
    {
        for(j=0;j<dim;++j)
        {
            summ=a->get(i,j)+b->get(i,j);
            c->sett(x*dim+i,y*dim+j,summ);
        }
    }
}

void matrix_multiply(matrix *a,matrix *b,matrix *c,int x1,int y1,int x2,int y2,int dim)
{
    if(dim==1)
    {
        c->sett(0,0,a->get(x1,y1)*b->get(x2,y2));
        return;
    }
    matrix *one=new matrix(dim/2);
    matrix *two=new matrix(dim/2);
    matrix *three=new matrix(dim/2);
    matrix *four=new matrix(dim/2);
    matrix *five=new matrix(dim/2);
    matrix *six=new matrix(dim/2);
    matrix *seven=new matrix(dim/2);
    matrix *eight=new matrix(dim/2);


    matrix_multiply(a,b,one,x1,y1,x2,y2,dim/2);
    matrix_multiply(a,b,two,x1,y1+dim/2,x2+dim/2,y2,dim/2);
    matrix_multiply(a,b,three,x1,y1,x2,y2+dim/2,dim/2);
    matrix_multiply(a,b,four,x1,y1+dim/2,x2+dim/2,y2+dim/2,dim/2);
    matrix_multiply(a,b,five,x1+dim/2,y1,x2,y2,dim/2);
    matrix_multiply(a,b,six,x1+dim/2,y1+dim/2,x2+dim/2,y2,dim/2);
    matrix_multiply(a,b,seven,x1+dim/2,y1,x2,y2+dim/2,dim/2);
    matrix_multiply(a,b,eight,x1+dim/2,y1+dim/2,x2+dim/2,y2+dim/2,dim/2);

    add1(c,one,two,0,0);
    add1(c,three,four,0,1);
    add1(c,five,six,1,0);
    add1(c,seven,eight,1,1);

}


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

    freopen("Matrix Multiplication.txt","r",stdin);
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

    matrix_multiply(a,b,c,0,0,0,0,dim);

    cout<<"Multiplied\n"<<*c<<endl;

	return 0;
}
