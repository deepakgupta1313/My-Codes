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

#define MAXN 1004

int n,m;

struct Point
{
    int x,y;
};

struct line_segment
{
    Point a,b;
};

int parentt[MAXN];

line_segment lines[MAXN];


inline int findd(int line_num)
{
    if(line_num!=parentt[line_num])
    {
        parentt[line_num]=findd(parentt[line_num]);
    }

    return parentt[line_num];
}


inline void unionn(int x,int y)
{
    parentt[x]=parentt[y];
}


inline int cross_productt(Point p1,Point p2, Point p3)
{
    return (p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x);
}

inline int which_side(Point p1, Point p2, Point p3)
{
    return cross_productt(p1,p2,p3);
}

inline bool in_between(int x,int y,int z)
{
    return (x<=y && y<=z);
}

inline bool on_line_segmentt(Point p1, Point p2, Point p3)
{
    return in_between(min(p1.x,p2.x),p3.x,max(p1.x,p2.x)) &&
            in_between(min(p1.y,p2.y),p3.y,max(p1.y,p2.y));
}


inline bool if_intersectt(Point p1, Point p2, Point p3, Point p4)
{
    int d1, d2, d3, d4;
	d1 = which_side(p3, p4, p1);
	d2 = which_side(p3, p4, p2);
	d3 = which_side(p1, p2, p3);
	d4 = which_side(p1, p2, p4);
	if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;
	if(!d1 && on_line_segmentt(p3, p4, p1)) return true;
	if(!d2 && on_line_segmentt(p3, p4, p2)) return true;
	if(!d3 && on_line_segmentt(p1, p2, p3)) return true;
	if(!d4 && on_line_segmentt(p1, p2, p4)) return true;
	return false;
}





int main()
{
    freopen("Text/ANTTT.txt","r",stdin);

    int cases;

    scanf("%d",&cases);
    int x,y;

    while(cases--)
    {
        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;++i)
        {
            parentt[i]=i;
            scanf("%d %d %d %d",&lines[i].a.x,&lines[i].a.y,&lines[i].b.x,&lines[i].b.y);
        }

        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                x=findd(i);
                y=findd(j);

                if(if_intersectt(lines[i].a,lines[i].b,lines[j].a,lines[j].b))
                {
                    unionn(x,y);
                }
            }
        }

        while(m--)
        {
            scanf("%d %d",&x,&y);

            x=findd(x);
            y=findd(y);

            if(x==y)
            {
                printf("YES\n");
            }
			else
            {
                printf("NO\n");
            }
        }
    }


    return 0;
}
