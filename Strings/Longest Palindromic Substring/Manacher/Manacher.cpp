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

char buff[1000];


string preProcess(string s)
{
    int n=s.size();
    if(n==0)
    {
        return "^$";
    }

    string ret="^";

    for(int i=0;i<n;++i)
    {
        ret+="#";
        ret+=s.substr(i,1);
    }

    ret+="#$";

    return ret;
}

string manacher(string s)
{
    printf("%s\n",s.c_str());
    string T=preProcess(s);
    //printf("%s\n",T.c_str());
    int n=T.size();

    int *P=new int[n];
    int C=0,R=0;

    for(int i=1;i<n-1;++i)
    {
        int i_mirror=2*C-i;

        P[i]=R>i?min(R-i,P[i_mirror]):0;

        while(T[i+1+P[i]]==T[i-1-P[i]])
        {
            ++P[i];
        }

        if(i+P[i]>R)
        {
            C=i;
            R=i+P[i];
        }
    }

    int maxLen=0;
    int centerIndex=0;

    for(int i=1;i<n-1;++i)
    {
        if(P[i]>maxLen)
        {
            maxLen=P[i];
            centerIndex=i;
        }
    }

    delete []P;

    if(n==2)
    {
        return "";
    }

    return s.substr((centerIndex-1-maxLen)/2,maxLen);
}


int main()
{

    freopen("Manacher.txt","r",stdin);

    while(gets(buff))
    {
        string str(buff);
        printf("%s\n",manacher(str).c_str());
    }

    return 0;
}

