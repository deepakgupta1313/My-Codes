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
#define VI veszor<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI veszor< VI >
#define PII pair< int,int >
#define VPII veszor< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 veszor<i64>
#define Vu64 veszor<u64>

#define RM 1000
#define MAXN 10001
#define MAXX 10000
#define MAXIT 500
#define INF 1e12
#define EPS 1e-3
#define MULL 0.998
#define PI acos(-1.0)


double X,Y;
int n;
double diff;

struct pointt
{
    double x,y,distt;
    pointt(double a,double b)
    {
        x=a;
        y=b;
    }
    pointt(){}
}arr[MAXN],curr,ans;

double distancee(pointt p1,pointt p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double Rand()
{
    return ((rand()%RM+1)/((double)RM));
}


double checkk(pointt p)
{
    double ret=INF;
    for(int i=1;i<=n;++i)
    {
        ret=min(ret,distancee(arr[i],p));
    }

    if(ret>ans.distt)
    {
        ans=p;
        ans.distt=ret;
    }

    return ret;
}

bool isValid(pointt p)
{
    if(p.x<0 || p.y<0 || p.x>X || p.y>Y)
    {
        return 0;
    }
    return 1;
}


void simulatedAnnealing()
{
    double T=sqrt(X*X+Y*Y)*0.5;

    for(;T > EPS;T *= MULL)
    {
        double angle = 2.0 * PI* Rand();

        pointt tmp(curr.x+T*cos(angle)*Rand(),curr.y+T*sin(angle)*Rand());

        if(!isValid(tmp))
        {
            continue;
        }

        diff=checkk(tmp)-checkk(curr);

        if(diff>=0 || exp(diff/T)>=Rand())
        {
            curr=tmp;
        }
    }

    T=0.5;

    for(int i=1;i<=MAXIT;++i)
    {
        double angle=2.0*PI*Rand();
        pointt tmp(ans.x+T*cos(angle)*Rand(),ans.y+T*sin(angle)*Rand());
        if(!isValid(tmp))
        {
            continue;
        }

        checkk(tmp);
    }
}

void MAIN()
{

    int cases;
    scanf("%d",&cases);

    while(cases--)
    {

        //scanf("%f %f %d",&X,&Y,&n);
        cin>>X>>Y>>n;
        curr=pointt(X*Rand(),Y*Rand());
        ans.distt=0;

        for(int i=1;i<=n;++i)
        {
            //printf("DD\n");
            //scanf("%f %f",&arr[i].x,&arr[i].y);
            cin>>arr[i].x>>arr[i].y;
        }

        simulatedAnnealing();
        printf("The safest point is (%.1f, %.1f).\n",ans.x,ans.y);
    }
}

int main()
{
    srand(19970804);

	freopen("Text/RUNAWAY.txt","r",stdin);

    MAIN();

	return 0;
}
