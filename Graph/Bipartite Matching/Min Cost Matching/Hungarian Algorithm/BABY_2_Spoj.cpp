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

#define MAXN 500

int n,cost[MAXN][MAXN];
int lx[MAXN],ly[MAXN];
int max_match,xy[MAXN],yx[MAXN],prevv[MAXN];
bool S[MAXN],T[MAXN];
int slack[MAXN],slackx[MAXN];


void init_labels()
{
    MSET(lx,0);
    MSET(ly,0);

    for(int x=0;x<n;++x)
    {
        for(int y=0;y<n;++y)
        {
            lx[x]=max(lx[x],cost[x][y]);
        }
    }
}


void update_labels()
{
    int x,y,delta=INT_MAX;

    for(y=0;y<n;++y)
    {
        if(!T[y])
        {
            delta=min(delta,slack[y]);
        }
    }

    for(x=0;x<n;++x)
    {
        if(S[x])
        {
            lx[x]-=delta;
        }
    }

    for(y=0;y<n;++y)
    {
        if(T[y])
        {
            ly[y]+=delta;
        }
    }

    for(y=0;y<n;++y)
    {
        if(!T[y])
        {
            slack[y]-=delta;
        }
    }
}


void add_to_tree(int x,int prevx)
{
    S[x]=true;
    prevv[x]=prevx;
    int ti;

    for(int y=0;y<n;++y)
    {
        ti=lx[x]+ly[y]-cost[x][y];

        if(ti<slack[y])
        {
            slack[y]=ti;
            slackx[y]=x;
        }
    }
}


int q[MAXN],headd,taill;

void augment()
{
    int x,y,root;

    headd=taill=0;
    MSET(S,0);
    MSET(T,0);
    MSET(prevv,-1);


    for(x=0;x<n;++x)
    {
        if(xy[x]==-1)
        {
            q[taill++]=root=x;
            prevv[root]=-2;
            S[root]=true;
            break;
        }
    }


    for(y=0;y<n;++y)
    {
        slack[y]=lx[root]+ly[y]-cost[root][y];
        slackx[y]=root;
    }


    while(true)
    {
        while(headd<taill)
        {
            x=q[headd++];

            for(y=0;y<n;++y)
            {
                if(cost[x][y]==lx[x]+ly[y] && !T[y])
                {
                    if(yx[y]==-1)
                    {
                        break;
                    }

                    T[y]=true;
                    q[taill++]=yx[y];
                    add_to_tree(yx[y],x);
                }
            }

            if(y<n)
            {
                break;
            }
        }

        if(y<n)
        {
            break;
        }


        update_labels();

        headd=taill=0;

        for(y=0;y<n;++y)
        {
            if(!T[y] && slack[y]==0)
            {
                if(yx[y]==-1)
                {
                    x=slackx[y];
                    break;
                }

                T[y]=true;

                if(!S[yx[y]])
                {
                    q[taill++]=yx[y];
                    add_to_tree(yx[y],slackx[y]);
                }
            }
        }

        if(y<n)
        {
            break;
        }
    }

    ++max_match;

    for(int cx = x,cy = y,ty;cx!=-2;cx = prevv[cx],cy = ty){
		ty = xy[cx];
		yx[cy] = cx;
		xy[cx] = cy;
	}
}




int hungarian(){
	int ret = 0;
	max_match = 0;
	memset(xy,-1,sizeof(xy));
	memset(yx,-1,sizeof(yx));

	init_labels();
	for(int i = 0;i<n;++i) augment();

	for(int x = 0;x<n;++x)
		ret += cost[x][xy[x]];

	return ret;
}


int main()
{
    freopen("Text/BABY.txt","r",stdin);

    int ya[16],yb[16];

    while(true)
    {
        scanf("%d",&n);

        if(n==0)
        {
            break;
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",ya+i);
        }

        for(int i=0;i<n;++i)
        {
            scanf("%d",yb+i);
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cost[i][j]=-abs(i-j)-abs(ya[i]-yb[j]);
            }
        }

        printf("%d\n",-hungarian());
    }



    return 0;
}
