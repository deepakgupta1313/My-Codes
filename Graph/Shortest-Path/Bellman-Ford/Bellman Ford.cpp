#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define i64 long long
#define pb push_back

#define INF 99999999
#define MAX_NODES 10
#define pii pair<int,int>
#define vpii vector< pii >

int pre[MAX_NODES];
int dist[MAX_NODES];
int nodes,edges;

vpii edge_array[MAX_NODES];


void init(int start_node)
{
    int i,j;
    fill(pre,pre+MAX_NODES,-1);
    fill(dist,dist+MAX_NODES,INF);
    dist[start_node]=0;
}

bool bellman_ford(int start_node)
{
    bool ret=true;
    init(start_node);

    int i,j,k,sz,temp;

    for(i=0;i<nodes-1;++i)
    {
        for(j=0;j<nodes;++j)
        {
            sz=edge_array[j].size();
            for(k=0;k<sz;++k)
            {
                if(dist[j]<INF)
                {
                    temp=dist[j]+edge_array[j][k].second;
                    if(temp<dist[edge_array[j][k].first])
                    {
                        dist[edge_array[j][k].first]=temp;
                        pre[edge_array[j][k].first]=j;
                    }
                }
            }
        }
    }


    for(j=0;j<nodes;++j)
    {
        sz=edge_array[j].size();
        for(k=0;k<sz;++k)
        {
            if(dist[j]<INF)
            {
                temp=dist[j]+edge_array[j][k].second;
                if(temp<dist[edge_array[j][k].first])
                {
                    dist[edge_array[j][k].first]=-INF;
                    ret=false;
                }
            }
        }
    }



    return ret;
}

void display()
{
    int i,j;

    printf("NO\tDist\tPre\n");
    for(i=0;i<nodes;++i)
    {
        printf("%d\t%d\t%d\n",i,dist[i],pre[i]);
    }
}

int main()
{
    freopen("Bellman Ford.txt","r",stdin);
    int i,j,node1,node2,weight;

    scanf("%d",&nodes);
    scanf("%d",&edges);

    for(i=0;i<edges;++i)
    {
        scanf("%d %d %d",&node1,&node2,&weight);
        edge_array[node1].pb(make_pair(node2,weight));
    }

    if(!bellman_ford(0))
    {
        printf("Negative Cycle\n");
    }
    display();

    return 0;
}

