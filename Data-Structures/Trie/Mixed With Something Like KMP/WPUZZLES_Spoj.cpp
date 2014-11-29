#include<bits/stdc++.h>
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


#define MAXN 1002
#define MAXD 1000001
int m,n,w;
char grid[MAXN][MAXN];
char arr[MAXN][MAXN];
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int xs[MAXN],ys[MAXN];
int dirr[MAXN];
int lns[MAXN];
int fail[MAXD];
int nodes;
int nxt[MAXD][26];
int endd[MAXD];
int root;


inline int createNode()
{
    MSET(nxt[nodes],-1);
    endd[nodes++]=-1;

    return nodes-1;
}

inline void init()
{
    nodes=0;
    root=createNode();
}


inline void insertt(int pos)
{
    int prs=root;

    int ln=lns[pos];
    int lr;

    for(int i=0;i<ln;++i)
    {
        lr=arr[pos][i]-'A';

        if(nxt[prs][lr]==-1)
        {
            nxt[prs][lr]=createNode();;
        }
        prs=nxt[prs][lr];
    }
    endd[prs]=pos;
}


void buildd()
{
    fail[root]=root;
    queue<int> q;

    q.push(root);
    int prs;
    int i;

    while(!q.empty())
    {
        prs=q.front();
        q.pop();

        for(i=0;i<26;++i)
        {
            if(nxt[prs][i]==-1)
            {
                nxt[prs][i]=prs==root?root:nxt[fail[prs]][i];
            }
            else
            {
                fail[nxt[prs][i]]=prs==root?root:nxt[fail[prs]][i];
                q.push(nxt[prs][i]);
            }
        }
    }
}


void searchh(int x,int y,int k)
{
    int prs=root;

    while(x>=0 && y>=0 && x<m  && y<n)
    {
        prs=nxt[prs][grid[x][y]-'A'];

        if(endd[prs]>=0)
        {
            xs[endd[prs]]=x-(lns[endd[prs]]-1)*dx[k];
            ys[endd[prs]]=y-(lns[endd[prs]]-1)*dy[k];
            dirr[endd[prs]]=k;
        }

        x+=dx[k];
        y+=dy[k];
    }
}

void solve()
{
    int i;

    for(i=0;i<m;++i)
    {
        searchh(i,0,1);
        searchh(i,0,2);
        searchh(i,0,3);

        searchh(i,n-1,5);
        searchh(i,n-1,6);
        searchh(i,n-1,7);
    }

    for(i=0;i<n;++i)
    {
        searchh(0,i,3);
        searchh(0,i,4);
        searchh(0,i,5);

        searchh(m-1,i,7);
        searchh(m-1,i,0);
        searchh(m-1,i,1);
    }

    for(i=0;i<w;++i)
    {
        printf("%d %d %c\n",xs[i],ys[i],dirr[i]+'A');
    }
}

int main()
{
    freopen("Text/WPUZZLES.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    int i;
    while(cases--)
    {
        init();
        scanf("%d %d %d",&m,&n,&w);

        for(i=0;i<m;++i)
        {
            scanf("%s",&grid[i]);
        }

        for(i=0;i<w;++i)
        {
            scanf("%s",&arr[i]);
            lns[i]=strlen(arr[i]);
            insertt(i);
        }

        buildd();

        solve();

        printf("\n");
    }
    return 0;
}
