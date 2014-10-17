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
#include <cassert>


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

#define MAXN 250005

int tail=0,num_states=0,childd[MAXN<<1][26],prevv[MAXN<<1],state_len[MAXN<<1],tarr[MAXN<<1],q[MAXN<<1],ct[MAXN<<1],ans[MAXN];
char arr[MAXN];

void insertt(int val,int pos)
{
    int p=tail,np=++num_states;
    state_len[np]=pos;
    tail=np;
    ++ct[np];

    for(;p!=-1 && !childd[p][val];p=prevv[p])
    {
        childd[p][val]=np;
    }

    if(p==-1)
    {
        return;
    }
    else
    {
        int q=childd[p][val];
        if(state_len[q]==state_len[p]+1)
        {
            prevv[np]=q;
        }
        else
        {
            state_len[++num_states]=state_len[p]+1;
            int nq=num_states;
            memcpy(childd[nq],childd[q],sizeof(childd[nq]));
            prevv[nq]=prevv[q];
            prevv[q]=prevv[np]=nq;

            for(;p!=-1 && childd[p][val]==q;p=prevv[p])
            {
                childd[p][val]=nq;
            }
        }
    }
}


int main()
{
    freopen("Text/NSUBSTR.txt","r",stdin);

    prevv[0]=-1;

    scanf("%s",arr);

    int len=strlen(arr);

    for(int i=0;i<len;++i)
    {
        insertt(arr[i]-'a',i+1);
    }

    for(int i=1;i<=num_states;++i)
    {
        ++tarr[state_len[i]];
    }

    for(int i=1;i<=num_states;++i)
    {
        tarr[i]+=tarr[i-1];
    }

    for(int i=1;i<=num_states;++i)
    {
        q[tarr[state_len[i]]--]=i;
    }

    for(int i=num_states;i>0;--i)
    {
        ans[state_len[q[i]]]=max(ans[state_len[q[i]]],ct[q[i]]);
        ct[prevv[q[i]]]+=ct[q[i]];
    }

    for(int i=1;i<=len;++i)
    {
        printf("%d\n",ans[i]);
    }

    return 0;
}
