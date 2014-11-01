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

#define MAXN 1002


#define bool int
#define false 0
#define true 1



struct surface_index
{
    int level;
    int indexx;
} surface_indexes[MAXN];

struct edge
{
    int x,y;
};


struct surface
{
    bool clockwise;
    int area,innerx,innery,edge_ct,minuss;
    edge edges[MAXN];
}surfaces[MAXN];

int surface_ct;

int cmp(const void *x,const void *y)
{
    const surface_index *a=(surface_index *)x;
    const surface_index *b=(surface_index *)y;

    if(a->level==b->level)
    {
        return (a->indexx<b->indexx)?-1:1;
    }

    return (a->level<b->level)?-1:1;
}

bool covers(int s_index,int innerx,int innery)
{
    int mxy=-999999999;
    bool ret=false;
    int mnx,mxx;
    int y;
    int nxt;

    for(int i=0;i<surfaces[s_index].edge_ct;++i)
    {
        nxt=(i==surfaces[s_index].edge_ct-1)?0:i+1;
        if(surfaces[s_index].edges[i].x==surfaces[s_index].edges[nxt].x)
        {
            continue;
        }

        y=surfaces[s_index].edges[i].y;

        mnx=min(surfaces[s_index].edges[i].x,surfaces[s_index].edges[nxt].x);
        mxx=max(surfaces[s_index].edges[i].x,surfaces[s_index].edges[nxt].x);

        if(innery<y || y<mxy || innerx<mnx || innerx>=mxx)
        {
            continue;
        }

        ret=(surfaces[s_index].edges[i].x<surfaces[s_index].edges[nxt].x)
            ^surfaces[s_index].clockwise;

        mxy=y;

    }

    return ret;
}

int covering_surface(int innerx,int innery,int st_index)
{
    int level=surface_indexes[st_index].level;
    int indexx;
    int i;

    for(i=st_index;i>=0 && surface_indexes[i].level==level;--i);

    for(;i>=0;--i)
    {
        indexx=surface_indexes[i].indexx;
        if(covers(indexx,innerx,innery))
        {
            return indexx;
        }
    }

    return -1;
}


void solve()
{
    int num_surfaces,num_edges,dx,dy,x,y,level,volume;
    bool not_horizontal;

    scanf("%d",&num_surfaces);

    surface_ct=0;
    int nxt;
    int indexx,coverr;

    for(int i=0;i<num_surfaces;++i)
    {
        scanf("%d",&num_edges);

        not_horizontal=false;

        for(int j=0;j<num_edges;++j)
        {
            scanf("%d %d %d",&surfaces[surface_ct].edges[j].x,
                            &surfaces[surface_ct].edges[j].y,
                            &level);

            if(!j)
            {
                surface_indexes[surface_ct].level=level;
            }
            else if(level != surface_indexes[surface_ct].level)
            {
                not_horizontal=true;
            }
        }

        if(not_horizontal)
        {
            continue;
        }

        surfaces[surface_ct].edge_ct=num_edges;
        surface_indexes[surface_ct].indexx=surface_ct;

        surfaces[surface_ct].area=0;

        for(int j=0;j<num_edges;++j)
        {
            nxt=(j==num_edges-1)?0:j+1;
            if(surfaces[surface_ct].edges[j].x==
               surfaces[surface_ct].edges[nxt].x)
            {
                continue;
            }

            surfaces[surface_ct].area+=surfaces[surface_ct].edges[j].y*
            (surfaces[surface_ct].edges[nxt].x-surfaces[surface_ct].edges[j].x);
        }

        if(surfaces[surface_ct].area>0)
        {
            surfaces[surface_ct].clockwise=true;
        }
        else
        {
            surfaces[surface_ct].clockwise=false;
            surfaces[surface_ct].area=-surfaces[surface_ct].area;
        }


        x=surfaces[surface_ct].edges[0].x;
        dx=surfaces[surface_ct].edges[1].x-x;

        y=surfaces[surface_ct].edges[0].y;
        dy=surfaces[surface_ct].edges[1].y-y;

        surfaces[surface_ct].innerx=x;
        surfaces[surface_ct].innery=y;

        if(surfaces[surface_ct].clockwise)
        {
            if(dy<0)
            {
                --surfaces[surface_ct].innerx;
                --surfaces[surface_ct].innery;
            }
            else if(dx<0)
            {
                --surfaces[surface_ct].innerx;
            }
            else if(dx>0)
            {
                --surfaces[surface_ct].innery;
            }
        }
        else
        {
            if(dx<0)
            {
                --surfaces[surface_ct].innerx;
                --surfaces[surface_ct].innery;
            }
            else if(dy>0)
            {
                --surfaces[surface_ct].innerx;
            }
            else if(dy<0)
            {
                --surfaces[surface_ct].innery;
            }
        }

        ++surface_ct;
    }

        qsort(surface_indexes,surface_ct,sizeof(surface_index),cmp);

        volume=0;

        for(int i=0;i<surface_ct;++i)
        {
            indexx=surface_indexes[i].indexx;
            coverr=covering_surface(surfaces[indexx].innerx,
                                    surfaces[indexx].innery,i);
            if(coverr==-1)
            {
                surfaces[indexx].minuss=true;
            }
            else
            {
                surfaces[indexx].minuss=!surfaces[coverr].minuss;
            }

            if(surfaces[indexx].minuss)
            {
                volume-=surfaces[indexx].area*surface_indexes[i].level;
            }
            else
            {
                volume+=surfaces[indexx].area*surface_indexes[i].level;
            }
        }

        //volume=abs(volume);

    printf("The bulk is composed of %d units.\n", volume);
}


int main()
{
    freopen("Text/BULK.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    while(cases--)
    {
        solve();
    }

    return 0;
}

