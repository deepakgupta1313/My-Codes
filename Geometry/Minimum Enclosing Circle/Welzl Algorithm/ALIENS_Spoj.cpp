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


//#define pointt complex<double>
//#define vpointt vector< pointt >


typedef complex<double> pointt;
typedef vector<pointt> vpointt;


#define EPS 1e-5

template<class T> T sqr(T x){return x*x;}


double calc_hypotenuse(double x,double y)
{
    return sqrt(x*x+y*y);
}


class Circle
{
public :
    double x,y,r;

    Circle(double x,double y,double r):x(x),y(y),r(r){}

    bool contains(pointt p)
    {
        return sqr(p.real()-x)+sqr(p.imag()-y)<r*r+EPS;
    }
};


Circle getCircumCircle(pointt a,pointt b)
{
    pointt c=(a+b)/2.0;
    double r=abs(a-c);
    return Circle(c.real(),c.imag(),r);
}


Circle getCircumCircle(pointt a,pointt b,pointt c)
{
    b-=a;
    c-=a;

    double Bx=b.real();
    double By=b.imag();
    double Cx=c.real();
    double Cy=c.imag();
    double d=2*(Bx*Cy-By*Cx);
    double z1=Bx*Bx+By*By;
    double z2=Cx*Cx+Cy*Cy;
    double cx=Cy*z1-By*z2;
    double cy=Bx*z2-Cx*z1;
    double x=cx/d;
    double y=cy/d;
    double r=calc_hypotenuse(x,y);

    return Circle(x+a.real(),y+a.imag(),r);
}

Circle min_enclosing_circle_with_2_points(vpointt &points,pointt q1,pointt q2)
{
    Circle ret=getCircumCircle(q1,q2);

    for(int i=0;i<points.size();++i)
    {
        if(!ret.contains(points[i]))
        {
            ret=getCircumCircle(q1,q2,points[i]);
        }
    }

    return ret;
}


Circle min_enclosing_circle_with_1_point(vpointt &points,pointt q)
{
    random_shuffle(points.begin(),points.end());

    Circle ret=getCircumCircle(points[0],q);

    for(int i=1;i<points.size();++i)
    {
        if(!ret.contains(points[i]))
        {
            vpointt P;
            copy(points.begin(),points.begin()+i,back_inserter(P));
            ret=min_enclosing_circle_with_2_points(P,points[i],q);
        }
    }

    return ret;
}


Circle min_enclosing_circle(vpointt points)
{
    if(points.size()==0)
    {
        return Circle(0,0,0);
    }

    if(points.size()==1)
    {
        return Circle(points[0].real(),points[0].imag(),0);
    }

    random_shuffle(points.begin(),points.end());

    Circle ret=getCircumCircle(points[0],points[1]);

    for(int i=2;i<points.size();++i)
    {
        if(!ret.contains(points[i]))
        {
            vpointt P;
            copy(points.begin(),points.begin()+i,back_inserter(P));
            ret=min_enclosing_circle_with_1_point(P,points[i]);
        }
    }

    return ret;
}


int main()
{
    freopen("Text/ALIENS.txt","r",stdin);


    int cases,n;
    double x,y;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&n);
        vpointt p(n);

        for(int i=0;i<n;++i)
        {
            scanf("%lf %lf",&x,&y);
            p[i]=pointt(x,y);
        }

        Circle ret=min_enclosing_circle(p);

        printf("%.2f\n",ret.r);
        printf("%.2f %.2f\n",ret.x,ret.y);
    }




    return 0;
}
