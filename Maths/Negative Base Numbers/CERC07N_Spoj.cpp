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

#define MAXN 100
char a[MAXN],b[MAXN];

int fromm(char *vall,int basee)
{

    int ret=0;

    for(int i=0;vall[i];++i)
    {
        ret*=basee;
        ret+=vall[i]-'0';
    }

    return ret;
}

string too(int vall,int basee)
{
    string ret="";
    int remm;

    while(vall)
    {
        remm=vall%basee;
        vall/=basee;

        if(remm<0)
        {
            ++vall;
            remm-=basee;
        }
        ret.PB(remm+'0');
    }

    if(ret.length()==0)
    {
        ret.PB('0');
    }

    reverse(ret.begin(),ret.end());

    return ret;
}


int main()
{
    freopen("Text/CERC07N.txt","r",stdin);
    int n,basee,vall;

    while(true)
    {
        scanf("%s",a);

        if(a[0]=='e')
        {
            break;
        }

        scanf("%s",b);


        if(a[0]=='t')
        {
            sscanf(a+2,"%d",&basee);
            sscanf(b,"%d",&vall);
            printf("%s\n",too(vall,basee).c_str());

        }
        else if(a[0]=='f')
        {
            sscanf(a+4,"%d",&basee);
            printf("%d\n",fromm(b,basee));
        }
    }



    return 0;
}
