#include <bits/stdc++.h>

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

#define MAXN 2000006

int arr[MAXN],summ[MAXN],qa[MAXN],qb[MAXN],n,sa,sb,ea,eb;

void push(int v)
{
    qa[ea++]=v;

    while(sb!=eb && qb[eb-1]>v)
    {
        --eb;
    }

    qb[eb++]=v;
}

void pop()
{
    if(sa!=ea)
    {
        if(qa[sa]==qb[sb])
        {
            ++sb;
        }
        ++sa;
    }
}

int get_minn()
{
    if(sb==eb)
    {
        return -1;
    }

    return qb[sb];
}


int main()
{
    freopen("Text/PARSUMS.txt","r",stdin);

    while(true)
    {
        scanf("%d",&n);

        if(!n)
        {
            break;
        }

        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
            arr[i+n]=arr[i];
        }

        for(int i=1;i<=(n<<1);++i)
        {
            summ[i]=summ[i-1]+arr[i];
        }

        sa=sb=ea=eb=0;

        for(int i=1;i<=n;++i)
        {
            push(summ[i]);
        }

        int ans=0;


        for(int i=n+1;i<=(n<<1);++i)
        {
            if(get_minn()-summ[i-n-1]>=0)
            {
                ++ans;
            }
            pop();
            push(summ[i]);
        }

        printf("%d\n",ans);
    }

    return 0;
}

