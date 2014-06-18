//          Assume max size of a set is 32

#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

int s_union(int set1,int set2)
{
    return set1|set2;
}

int s_intersection(int set1,int set2)
{
    return set1&set2;
}

int s_subtraction(int set1,int set2)
{
    return set1&(~set2);
}

bool s_isEmpty(int set1)
{
    return set1==0;
}

bool s_containsElement(int set1,int elem_num)
{
    return ((set1&(1<<elem_num))!=0);
}

int s_generate_0_to_x(int x)
{
    return (1<<(x+1))-1;
}

int s_insert(int set1,int elem_num)
{
    return set1|(1<<elem_num);
}

int s_remove(int set1,int elem_num)
{
    return set1&(~(1<<elem_num));
}

int s_negation(int set1,int s_size)
{
    return ((1<<s_size)-1)&(~set1);
}

bool s_has_exactly_one_elem(int set1)
{
    return (set1>0 && (set1&(set1-1)==0));
}

int s_delete_smallest(int set1)
{
    return set1&(set1-1);
}

int s_remove_all_but_smallest(int set1)
{
    return set1&(~(set1-1));
}

int s_bitcount(int set1)
{
    int ret=0;

    ret=(set1&0x55555555) + ((set1>>1) & 0x55555555);
    ret=(ret&0x33333333) + ((ret>>2) & 0x33333333);
    ret=(ret&0x0F0F0F0F) + ((ret>>4) & 0x0F0F0F0F);
    ret=(ret&0x00FF00FF) + ((ret>>8) & 0x00FF00FF);
    ret=(ret&0x0000FFFF) + ((ret>>16));

    return ret;
}


void s_iterate_over_subsets_of_size_le_m(int n,int m)
{
    for(int i=0;i<(1<<n);i = s_bitcount(i)<m ? (i+1) : ((i|(i-1))+1))
    {

    }
}


void s_iterate_over_subsets_of_a_subset(int n)
{
    for(int i=0;i<(1<<n);++i)
    {
        for(int i2=i;i2>0;i2=(i2-1)&i)
        {

        }
    }
}


unsigned int s_next_subset_with_same_number_of_elem(unsigned int v)
{
    unsigned int t = (v | (v - 1)) + 1;
    v = t | ((((t & -t) / (v & -v)) >> 1) - 1);

    return v;
}



void s_iterate_over_subsets_of_size_m(unsigned int n,unsigned int m)
{
    unsigned int st=(1ull<<m)-1;
    unsigned int en=st<<(n-m);
    int i=1;
    while(st!=en)
    {
        printf("%d\t%u\n",i,st);
        unsigned int t = (st | (st - 1)) + 1;
        st = t | ((((t & -t) / (st & -st)) >> 1) - 1);
        ++i;
    }

    // Iterate here on the last
    printf("%d\t%u\n",i,st);


}


int main()
{

    s_iterate_over_subsets_of_size_m(32,0);
    return 0;
}

