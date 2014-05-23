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
        //memset(data,0,sizeof(data));

        int i;

        for(i=0;i<dimension*dimension;++i)
        {
            data[i]=0;
        }
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

void copy_mat(matrix *to,matrix *from,int x1,int y1)
{
    int dim=to->getDimension();
    int i,j;

    for(i=0;i<dim;++i)
    {
        for(j=0;j<dim;++j)
        {
            to->sett(i,j,from->get(x1+i,y1+j));
        }
    }
}

void add_sub(matrix *to,matrix *a,matrix *b,int fl)
{
    int dim=to->getDimension();
    int i,j;

    for(i=0;i<dim;++i)
    {
        for(j=0;j<dim;++j)
        {
            to->sett(i,j,a->get(i,j)+fl*(b->get(i,j)));
        }
    }
}

void add_sub2(matrix *to,matrix *from,int x1,int y1,int fl)
{
    int dim=from->getDimension();
    int i,j;
    int summ;

    for(i=0;i<dim;++i)
    {
        for(j=0;j<dim;++j)
        {
            summ=fl*from->get(i,j);
            summ+=to->get(x1*dim+i,y1*dim+j);

            to->sett(x1*dim+i,y1*dim+j,summ);
        }
    }
}


void strassen(matrix *a,matrix *b,matrix *c)
{
    int x1=0,y1=0,x2=0,y2=0;

    int dim=a->getDimension();

    if(dim==1)
    {
        c->sett(0,0,(a->get(0,0))*(b->get(0,0)));
        return;
    }

    matrix *s1=new matrix(dim/2);
    matrix *s2=new matrix(dim/2);
    matrix *s3=new matrix(dim/2);
    matrix *s4=new matrix(dim/2);
    matrix *s5=new matrix(dim/2);
    matrix *s6=new matrix(dim/2);
    matrix *s7=new matrix(dim/2);
    matrix *s8=new matrix(dim/2);
    matrix *s9=new matrix(dim/2);
    matrix *s10=new matrix(dim/2);

    matrix *a11=new matrix(dim/2);
    matrix *a12=new matrix(dim/2);
    matrix *a21=new matrix(dim/2);
    matrix *a22=new matrix(dim/2);

    matrix *b11=new matrix(dim/2);
    matrix *b12=new matrix(dim/2);
    matrix *b21=new matrix(dim/2);
    matrix *b22=new matrix(dim/2);

    matrix *p1=new matrix(dim/2);
    matrix *p2=new matrix(dim/2);
    matrix *p3=new matrix(dim/2);
    matrix *p4=new matrix(dim/2);
    matrix *p5=new matrix(dim/2);
    matrix *p6=new matrix(dim/2);
    matrix *p7=new matrix(dim/2);


    copy_mat(a11,a,x1,y1);
    copy_mat(a12,a,x1,y1+dim/2);
    copy_mat(a21,a,x1+dim/2,y1);
    copy_mat(a22,a,x1+dim/2,y1+dim/2);


    copy_mat(b11,b,x2,y2);
    copy_mat(b12,b,x2,y2+dim/2);
    copy_mat(b21,b,x2+dim/2,y2);
    copy_mat(b22,b,x2+dim/2,y2+dim/2);


    add_sub(s1,b12,b22,-1);
    add_sub(s2,a11,a12,1);
    add_sub(s3,a21,a22,1);
    add_sub(s4,b21,b11,-1);
    add_sub(s5,a11,a22,1);
    add_sub(s6,b11,b22,1);
    add_sub(s7,a12,a22,-1);
    add_sub(s8,b21,b22,1);
    add_sub(s9,a11,a21,-1);
    add_sub(s10,b11,b12,1);

    strassen(a11,s1,p1);
    strassen(s2,b22,p2);
    strassen(s3,b11,p3);
    strassen(a22,s4,p4);
    strassen(s5,s6,p5);
    strassen(s7,s8,p6);
    strassen(s9,s10,p7);

    add_sub2(c,p5,0,0,1);
    add_sub2(c,p4,0,0,1);
    add_sub2(c,p2,0,0,-1);
    add_sub2(c,p6,0,0,1);

    add_sub2(c,p1,0,1,1);
    add_sub2(c,p2,0,1,1);


    add_sub2(c,p3,1,0,1);
    add_sub2(c,p4,1,0,1);


    add_sub2(c,p5,1,1,1);
    add_sub2(c,p1,1,1,1);
    add_sub2(c,p3,1,1,-1);
    add_sub2(c,p7,1,1,-1);

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
    cout<<*c;

    strassen(a,b,c);

    cout<<*c;

	return 0;
}
