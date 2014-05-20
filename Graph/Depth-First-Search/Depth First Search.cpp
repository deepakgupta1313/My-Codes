// Graph is assumed to be connected
// 0 is the root


#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<bitset>

using namespace std;

#define i64 long long
#define pb push_back

#define MAX_NODES 100

vector<int> gr[MAX_NODES];
int num_edges;
bitset<MAX_NODES> visited;


void dfs(int node)
{
    printf("%d\n",node);
    visited.set(node);
    int i,sz;

    sz=gr[node].size();

    for(i=0;i<sz;++i)
    {
        if(!visited.test(gr[node][i]))
        {
            dfs(gr[node][i]);
        }
    }
}

int main()
{
    freopen("Depth First Search.txt","r",stdin);

    int node1,node2;

    scanf("%d",&num_edges);

    for(int i=0;i<num_edges;++i)
    {
        scanf("%d %d",&node1,&node2);
        gr[node1].pb(node2);
        gr[node2].pb(node1);
    }

    dfs(0);
}
