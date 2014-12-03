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
#include<cmath>


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

#define MAXN 44
#define MAXM 44
#define INF 999999999999999LL
bool poss;
int n,m;
i64 ans;
int e;
int first_edge[MAXN];
int to[MAXM<<2];
i64 v[MAXM<<2];
int nxt[MAXM<<2];
int curr;
int indexx[MAXN],low_linkk[MAXN],on_stack[MAXN];
stack<int> st;
int fa[MAXN];

int idx;
void add_edge(int x,int y,i64 z)
{
    to[e]=y;
    v[e]=z;
    nxt[e]=first_edge[x];
    first_edge[x]=e++;

    to[e]=x;
    v[e]=z;
    nxt[e]=first_edge[y];
    first_edge[y]=e++;
}

void tarjan(int u)
{
    //printf("U\t%d\n",u);
    int v,i;
    indexx[u]=low_linkk[u]=idx++;
    st.push(u);
    on_stack[u]=1;
    int ti;

    for(int i=first_edge[u];i>=0;i=nxt[i])
    {
        ti=i/2;
        if(!(curr&(1<<ti)))
        {
            continue;
        }
        v=to[i];
        if(indexx[v]==-1)
        {
            fa[v]=u;
            tarjan(v);
            low_linkk[u]=min(low_linkk[u],low_linkk[v]);
        }
        else if(on_stack[v] && v!=fa[u])
        {
            low_linkk[u]=min(low_linkk[u],indexx[v]);
        }
    }

    //printf("%d\t%d\t%d\t%d\t%d\n",curr,u,st.size(),low_linkk[u],indexx[u]);
    if(low_linkk[u]==indexx[u])
    {

        if(u!=1 || st.size()!=n)
        {
            poss=false;
            return;
        }
    }


}

void solve()
{
    if(m<n)
    {
        poss=false;
        return;
    }
    int ct;
    i64 ti;
    int i;

    for(curr=1;curr<(1<<m);++curr)
    {
        poss=true;
        ct=__builtin_popcount(curr);
        if(ct<n)
        {
            poss=false;
            continue;
        }

        idx=0;
        MSET(indexx,-1);
        MSET(on_stack,0);
        MSET(low_linkk,0x7f);
        MSET(fa,0);
        while(!st.empty())
        {
            st.pop();
        }
        tarjan(1);
        if(!poss)
        {
            continue;
        }

        ti=0;


        for(i=0;i<m;++i)
        {
            if(curr&(1<<i))
            {
                ti+=v[2*i];
            }
        }
        //printf("%d\t%d\n",curr,ti);

        ans=min(ans,ti);
    }
}


int main()
{
    freopen("Text/RELINETS.txt","r",stdin);
    int cases=0;
    int x,y;
    i64 z;
    int i;

    while(true)
    {
        MSET(first_edge,-1);
        e=0;
        ++cases;
        poss=false;
        ans=INF;

        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
        {
            break;
        }

        for(i=0;i<m;++i)
        {
            scanf("%d %d %lld",&x,&y,&z);
            add_edge(x,y,z);
        }

        solve();
        if(n==1)
        {
            ans=0LL;
        }

        if(ans<INF)
        {
            printf("The minimal cost for test case %d is %d.\n",cases,ans);
        }
        else
        {
            printf("There is no reliable net possible for test case %d.\n",cases);
        }
    }



    return 0;
}
