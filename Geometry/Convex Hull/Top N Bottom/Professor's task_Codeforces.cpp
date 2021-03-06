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
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define f first
#define s second
#define mp make_pair
typedef long long LL;
typedef pair<int,int> PI;
typedef map<int,int> MI;
typedef MI::iterator MII;
MI t,b;
LL cp(const PI &x,const PI &y,const PI &z)
{
	return (LL)(x.f-z.f)*(y.s-z.s)-(LL)(x.s-z.s)*(y.f-z.f);
}

bool ask(MI &h,const PI &x){
	MII i=h.lower_bound(x.f);

	if(i==h.end())return 0;

	if((*i).f==x.f)return x.s<=(*i).s;

	if(i==h.begin())return 0;

	MII j=i--;
	return cp(x,*j,*i)>=0;
}

void add(MI &h,const PI &x)
{
	h[x.f]=x.s;
	MII i=h.upper_bound(x.f);

	if(i!=h.end())
		for(MII j=i++;i!=h.end();j=i++)
			if(cp(*i,*j,x)<=0)h.erase(j);else break;

	i=h.find(x.f);

	if(i!=h.begin())
		for(MII j=--i;j!=h.begin();)
		{
			i=j--;
			if(cp(*i,*j,x)<=0)h.erase(i);else break;
		}
}
int main()
{
	freopen("Text/Professor's task.txt","r",stdin);

	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int mk,x,y;
		scanf("%d%d%d",&mk,&x,&y);
		bool ft=ask(t,mp(x,y)),fb=ask(b,mp(x,-y));

		if(mk==1)
		{
			if(!ft)add(t,mp(x,y));
			if(!fb)add(b,mp(x,-y));
		}
		else puts(ft&&fb?"YES":"NO");
	}
	return 0;
}
