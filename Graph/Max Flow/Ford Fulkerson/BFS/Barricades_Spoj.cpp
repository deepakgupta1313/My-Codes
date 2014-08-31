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


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

#define MAXN 11

int cap[MAXN][MAXN],flow[MAXN][MAXN],previ[MAXN];
int n,m;


int ford_fulkerson()
{
    int s=0,t=n-1;

    int ret=0;

    while(true)
    {
        MSET(previ,-1);

        queue<int> q;

        previ[s]=-2;

        q.push(s);

        while(!q.empty() && previ[t]==-1)
        {
            int u=q.front();
            q.pop();

            for(int v=0;v<n;++v)
            {
                if(previ[v]==-1)
                {
                    if(flow[v][u]>0 || flow[u][v]<cap[u][v])
                    {
                        previ[v]=u;
                        q.push(v);
                    }
                }
            }
        }


        if(previ[t]==-1)
        {
            break;
        }

        int bot=INT_MAX;

        for(int v=t,u=previ[v];u>=0;v=u,u=previ[v])
        {
            if(flow[v][u]>0)
            {
                bot=min(bot,flow[v][u]);
            }
            else
            {
                bot=min(bot,cap[u][v]-flow[u][v]);
            }
        }

        int u,v;
        for(v=t,u=previ[v];u>=0;v=u,u=previ[v])
        {
            printf("%d\t,",v);
            if(flow[v][u]>0)
            {
                flow[v][u]-=bot;
            }
            else
            {
                flow[u][v]+=bot;
            }
        }
        printf("%d\n",v);

        ret+=bot;
        printf("FLOW\t%d\n",ret);
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%d,%d\t",cap[i][j],flow[i][j]);
        }
        printf("\n");
    }

    return ret;

}

class Barricades  {
	public:

	    int minBarricadeWidth(int param0, VS param1)
	    {
	        MSET(cap,0);
	        MSET(flow,0);

	        int ret=0;

            n=param0;
            m=param1.size();
            int u,v,w;

            for(int i=0;i<m;++i)
            {
                stringstream ss(param1[i]);
                ss>>u>>v>>w;

                printf("%d\t%d\t%d\n",u,v,w);

                cap[u][v]=w;
                cap[v][u]=w;
            }

            ret=ford_fulkerson();
            return ret;

	    }


};

int main()
{

    //freopen("Text/Barricades .txt","r",stdin);
    Barricades  ss;

    int a=5;
    string b[]={"0 1 5","0 2 2","0 3 3","1 2 1","2 3 1","2 4 10","3 4 2"};

    VS y;

    arrayToVectorString(b,y,sizeof(b)/sizeof(*b));

    printf("%d\n",ss.minBarricadeWidth(a,y));

	return 0;
}
