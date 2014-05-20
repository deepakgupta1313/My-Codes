#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

#define i64 long long
#define inf 999999999

using namespace std;

struct edge
{
    int v;
    int w;
};

int n,src,dest;
map<string,int> mp;
char buff[20];
string str;

vector<edge> gr[10005];
bool visited[10005];
i64 dist[10005];

bool operator<(edge a,edge b)
{
    return (a.w)>(b.w);
}



i64 djk()
{
    int i,j,sz;
    i64 temp;
    memset(visited,0,sizeof(visited));
    fill(dist,dist+10005,inf);
    //cout<<src<<dest<<endl;

    priority_queue<edge> pq;
    dist[src]=0;

    pq.push((edge){src,0});

    while(!pq.empty() && !visited[dest])
    {
        edge p=pq.top();
        pq.pop();
        //cout<<p.v<<"\t"<<p.w<<endl;

        visited[p.v]=true;

        sz=gr[p.v].size();
        for(i=0;i<sz;++i)
        {
            if(!visited[gr[p.v][i].v])
            {
                temp=dist[p.v]+gr[p.v][i].w;
                if(temp<dist[gr[p.v][i].v])
                {
                    dist[gr[p.v][i].v]=temp;
                    //pq.push(gr[p.v][i]);
                    pq.push((edge){gr[p.v][i].v,temp});
                }
            }
        }

    }

    return dist[dest];

}

int main()
{
    //freopen("C:/Users/MINTOO/Desktop/Programs/Codeblocks/Spoj/Text/SHPATH.txt","r",stdin);
    freopen("SHPATH.txt","r",stdin);

    int cases,i,j,nr,cost,r,p;
    string name1,name2;

    scanf("%d",&cases);

    while(cases--)
    {
/*        if(cases>0)
        {
            scanf("%s",buff);
        }
*/
        for(i=0;i<10005;++i)
        {
            gr[i].clear();
        }

        scanf("%d",&n);
        for(i=1;i<=n;++i)
        {
            scanf("%s",buff);
            str=buff;
            mp[str]=i;

            scanf("%d",&p);

            for(j=0;j<p;++j)
            {
                scanf("%d %d",&nr,&cost);
                gr[i].push_back((edge){nr,cost});
                //gr[nr].push_back((edge){i,cost});
            }
        }

        scanf("%d",&r);

        for(i=0;i<r;++i)
        {
            scanf("%s",buff);
            name1=buff;
            src=mp[name1];

            scanf("%s",buff);
            name2=buff;
            dest=mp[name2];
            //cout<<dist[dest]<<endl;
            printf("%lld\n",djk());
        }

        //scanf("%s",buff);
    }

    return 0;
}

