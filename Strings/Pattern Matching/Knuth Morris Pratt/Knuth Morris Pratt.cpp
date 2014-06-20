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
#define VVI vector< VI >


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





int s_bitcount(unsigned int set1)
{
    int ret=0;

    ret=(set1&0x55555555) + ((set1>>1) & 0x55555555);
    ret=(ret&0x33333333) + ((ret>>2) & 0x33333333);
    ret=(ret&0x0F0F0F0F) + ((ret>>4) & 0x0F0F0F0F);
    ret=(ret&0x00FF00FF) + ((ret>>8) & 0x00FF00FF);
    ret=(ret&0x0000FFFF) + ((ret>>16));

    return ret;
}


string pat,text;
VI widths;
int n,m;


void kmp_preprocess()
{
    widths.clear();
    n=text.size();
    m=pat.size();
    widths.resize(m+1);

    int i=0,j=-1;
    widths[i]=j;

    while(i<m)
    {
        while(j>=0 && pat[i]!=pat[j])
        {
            j=widths[j];
        }
        ++i;
        ++j;
        widths[i]=j;
    }
}


void kmp_search()
{
    int i=0,j=0;

    while(i<n)
    {
        while(j>=0 && text[i]!=pat[j])
        {
            j=widths[j];
        }
        ++i;
        ++j;

        if(j==m)
        {
            printf("Found at %d\n",i-j);
            j=widths[j];
        }
    }
}



int main()
{

    pat="AABA";
    text="AABAACAADAABAAABAA";

    kmp_preprocess();
    kmp_search();

    return 0;
}

