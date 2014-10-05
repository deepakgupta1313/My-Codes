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
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>


using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>


const int MAXN=110000;

char str[MAXN];
int id[MAXN];
int sa[MAXN],rankk[MAXN],height[MAXN],c[MAXN],tmp[MAXN];
int n,m;

void suffix_array(int m)
{
    MSET(c,0);
    for(int i=0;i<n;++i)
    {
        ++c[rankk[i]=str[i]];
    }

    for(int i=1;i<m;++i)
    {
        c[i]+=c[i-1];
    }

    for(int i=0;i<n;++i)
    {
        sa[--c[rankk[i]]]=i;
    }

    for(int k=1;k<n;k<<=1)
    {
        for(int i=0;i<n;++i)
        {
            int j=sa[i]-k;
            if(j<0)
            {
                j+=n;
            }

            tmp[c[rankk[j]]++]=j;
        }

        int j=c[0]=sa[tmp[0]]=0;

        for(int i=1;i<n;++i)
        {
            if(rankk[tmp[i]]!=rankk[tmp[i-1]] || rankk[tmp[i]+k]!=rankk[tmp[i-1]+k])
            {
                c[++j]=i;
            }

            sa[tmp[i]]=j;
        }

        memcpy(rankk,sa,n*sizeof(int));
        memcpy(sa,tmp,n*sizeof(int));
    }
}

void calc_height()
{
    for(int i=0,k=0;i<n;height[rankk[i++]]=k)
    {
        k-=(k>0);
        int j=sa[rankk[i]-1];
        while(str[i+k]==str[j+k])
        {
            ++k;
        }
    }
}

int mx[MAXN],mn[MAXN];
int st[MAXN];


void update_max(int &a,int b)
{
    if(a==-1 || a<b)
    {
        a=b;
    }
}

void update_min(int &a,int b)
{
    if(a==-1 || a>b)
    {
        a=b;
    }
}

bool checkk(int len)
{
    int summ=0,topp=0;

    MSET(mx,-1);
    MSET(mn,-1);
    MSET(c,0);

    for(int i=0;i<n;++i)
    {
        if(height[i]>=len)
        {
            update_max(mx[id[sa[i]]],sa[i]);
            update_min(mn[id[sa[i]]],sa[i]);

            st[++topp]=id[sa[i]];

            if(mx[id[sa[i]]]-mn[id[sa[i]]]>=len)
            {
                if(!c[id[sa[i]]])
                {
                    ++summ;
                }

                c[id[sa[i]]]=true;

                if(summ>=m)
                {
                    return true;
                }
            }
        }
        else
        {
            summ=0;

            while(topp)
            {
                int t=st[topp--];
                mx[t]=mn[t]=-1;
                c[t]=false;
            }

            update_max(mx[id[sa[i]]],sa[i]);
            update_min(mn[id[sa[i]]],sa[i]);

            st[++topp]=id[sa[i]];
        }
    }

    return false;
}


int solve()
{
    int l=1,r=5001;

    while(l<r)
    {
        int midd=(l+r)>>1;

        if(checkk(midd))
        {
            l=midd+1;
        }
        else
        {
            r=midd;
        }
    }

    return l-1;
}


int main() {

	freopen("Text/PHRASES.txt","r",stdin);

	int cases;

	scanf("%d",&cases);

	while(cases--)
    {
        scanf("%d",&m);
        n=0;

        for(int i=0;i<m;++i)
        {
            scanf("%s",str+n);

            while(str[n])
            {
                id[n++]=i;
            }
            str[n++]=i+1;
        }

        str[n-1]=0;

        suffix_array(128);

        calc_height();

        printf("%d\n",solve());
    }



    return 0;
}
