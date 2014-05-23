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
    int dimension;
    int *data;

    matrix(int d)
    {
        dimension=d;
        data=new int(dimension*dimension);
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

    int get(int x,int y)
    {
        return data[x*dimension+y];
    }

    int set(int x,int y,int val)
    {
        data[x*dimension+y]=val;
    }
};

int main() {

    freopen("Matrix Multiplication.txt","r",stdin);
    int i,j;

    matrix a(2);
    a=a+a;


	return 0;
}
