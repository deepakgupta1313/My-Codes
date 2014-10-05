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

#define MAXX 100000

int dist[MAXX], to[MAXX<<1], nextt[MAXX<<1], firstt[MAXX], n;

int bfs(int s)
{
    int e,u,v;

    MSET(dist,-1);

    queue<int> q;
    q.push(s);
    dist[s]=0;

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(e=firstt[u];e>=0;e=nextt[e])
        {
            v=to[e];
            if(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }

    for(int i=0;i<n;++i)
    {
        if(dist[i]>dist[s])
        {
            s=i;
        }
    }

    return s;

}

int main()
{
    freopen("Text/GCPC11J.txt","r",stdin);

    int cases,x,y;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        MSET(firstt,-1);

        for(int i=0,e=0;i<n-1;++i)
        {
            scanf("%d %d",&x,&y);
            to[e]=y;
            nextt[e]=firstt[x];
            firstt[x]=e++;

            to[e]=x;
            nextt[e]=firstt[y];
            firstt[y]=e++;
        }

        printf("%d\n",(1+dist[bfs(bfs(0))])>>1);
    }


    return 0;
}
