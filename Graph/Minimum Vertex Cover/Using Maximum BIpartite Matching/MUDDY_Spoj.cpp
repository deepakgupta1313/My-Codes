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

#define MAXX 51
#define MAXN 2510
#define INF 999999999


struct data
{
    int l,r,i;

    data(int x,int y,int z)
    {
        l=x;
        r=y;
        i=z;
    }
};


VI edges[MAXN];
bool vis[MAXN];
int leftt[MAXN],rightt[MAXN],num_row,num_col,nr,nc;

char arr[MAXN][MAXN];



bool dfs(int u)
{
    if(vis[u])
    {
        return false;
    }

    vis[u]=true;
    int v;

    for(int i=0;i<edges[u].size();++i)
    {
        v=edges[u][i];

        if(rightt[v]==-1)
        {
            rightt[v]=u;
            leftt[u]=v;

            return true;
        }
    }


    for(int i=0;i<edges[u].size();++i)
    {
        v=edges[u][i];

        if(dfs(rightt[v]))
        {
            rightt[v]=u;
            leftt[u]=v;

            return true;
        }
    }


    return false;
}


int max_match()
{
    MSET(leftt,-1);
    MSET(rightt,-1);

    int ret=0;

    bool finn;

    do
    {
        finn=true;
        MSET(vis,0);

        for(int i=0;i<nr;++i)
        {
            if(leftt[i]==-1 && dfs(i))
            {
                finn=false;
            }
        }
    }
    while
    (
        !finn
    );


    for(int i=0;i<nr;++i)
    {
        if(leftt[i]!=-1)
        {
            ++ret;
        }
    }

    return ret;
}


int main()
{

    freopen("Text/MUDDY.txt","r",stdin);

    int cases;
    int st;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&num_row,&num_col);

        for(int i=0;i<num_row;++i)
        {
            scanf("%s",&arr[i]);
        }


        vector<data> rowd,cold;

        for(int i=0;i<num_row;++i)
        {
            for(int j=0;j<num_col;++j)
            {
                if(arr[i][j]=='*')
                {
                    st=j;
                    while(j<num_col && arr[i][j]=='*')
                    {
                        ++j;
                    }

                    rowd.PB(data(st,j-1,i));
                    --j;
                }
            }
        }


        for(int i=0;i<num_col;++i)
        {
            for(int j=0;j<num_row;++j)
            {
                if(arr[j][i]=='*')
                {
                    st=j;

                    while(j<num_row && arr[j][i]=='*')
                    {
                        ++j;
                    }

                    cold.PB(data(st,j-1,i));
                    --j;
                }
            }
        }


        nr=rowd.size();
        nc=cold.size();

        if(!nr || !nc)
        {
            printf("%d\n",max(nr,nc));
        }
        else
        {
            for(int i=0;i<nr;++i)
            {
                edges[i].clear();

                for(int j=0;j<nc;++j)
                {
                    if(cold[j].l<=rowd[i].i && rowd[i].i<=cold[j].r && rowd[i].l<=cold[j].i && cold[j].i<=rowd[i].r)
                    {
                        edges[i].PB(j);
                    }
                }
            }

            printf("%d\n",max_match());
        }

    }

    return 0;
}
