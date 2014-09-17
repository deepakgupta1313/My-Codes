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

#define MAXX 90099

char str[MAXX];
int rankk[MAXX],SA[MAXX];
int ct[MAXX],nextt[MAXX];
bool bh[MAXX],b2h[MAXX];
int longest_common_prefix[MAXX];
int substr_count[MAXX];


bool smaller_first_char(int a,int b)
{
    return str[a]<str[b];
}


void suffix_sort(int n)
{
    int i;
    int j,buckets;
    REP(i,n)
    {
        SA[i]=i;
    }

    sort(SA,SA+n,smaller_first_char);


    REP(i,n)
    {
        bh[i]= i==0 || str[SA[i-1]]!=str[SA[i]];
        b2h[i]=false;
    }

    for(int h=1;h<n;h<<=1)
    {
        buckets=0;
        for(i=0,j=0;i<n;i=j)
        {
            j=i+1;
            while(j<n && !bh[j])
            {
                ++j;
            }
            nextt[i]=j;
            ++buckets;
        }

        if(buckets==n)
        {
            break;
        }

        for(i=0;i<n;i=nextt[i])
        {
            ct[i]=0;
            for(j=i;j<nextt[i];++j)
            {
                rankk[SA[j]]=i;
            }
        }

        ct[rankk[n-h]]++;
        b2h[rankk[n-h]]=true;

        for(i=0;i<n;i=nextt[i])
        {
            for(j=i;j<nextt[i];++j)
            {
                int s=SA[j]-h;

                if(s>=0)
                {
                    int head=rankk[s];
                    rankk[s]=head+ct[head]++;
                    b2h[rankk[s]]=true;
                }
            }

            for(j=i;j<nextt[i];++j)
            {
                int s=SA[j]-h;
                if(s>=0 && b2h[rankk[s]])
                {
                    for(int k=rankk[s]+1;!bh[k] && b2h[k];++k)
                    {
                        b2h[k]=false;
                    }
                }
            }
        }

        REP(i,n)
        {
            SA[rankk[i]]=i;
            bh[i]|=b2h[i];
        }

    }

    REP(i,n)
    {
        rankk[SA[i]]=i;
    }
}



void calc_longest_common_prefix(int n)
{
    int h,i,j;
    REP(i,n)
    {
        rankk[SA[i]]=i;
    }
    longest_common_prefix[0]=0;

    for(i=0,h=0;i<n;++i)
    {
        if(rankk[i]>0)
        {
            j=SA[rankk[i]-1];
            while(i+h<n && j+h<n && str[i+h]==str[j+h])
            {
                ++h;
            }

            longest_common_prefix[rankk[i]]=h;
            if(h>0)
            {
                --h;
            }
        }
    }

}




int main()
{
    freopen("Text/SUBLEX.txt","r",stdin);


    int kth,t,diff,suffix_size;
    gets(str);
    int len=strlen(str);
    scanf("%d",&t);
    suffix_sort(len);
    calc_longest_common_prefix(len);

    int summ=0,i;

    REP(i,len)
    {
        suffix_size=len-SA[i];
        diff=suffix_size-longest_common_prefix[i];
        summ+=diff;
        substr_count[i]=summ;
    }

    while(t--)
    {
        scanf("%d",&kth);

        int first_entry=0;

        REP(i,len)
        {
            if(substr_count[i]>=kth)
            {
                first_entry=i;
                break;
            }
        }

        int shared_prefix_length=longest_common_prefix[first_entry];

        int idx,j;

        for(idx=SA[first_entry],j=0;j<shared_prefix_length;++j,++idx)
        {
            printf("%c",str[idx]);
        }

        for(int j=0;j<kth-substr_count[first_entry-1];++j,++idx)
        {
            printf("%c",str[idx]);
        }

        printf("\n");
    }

    return 0;
}


