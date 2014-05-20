#include<iostream>
#include<cstdio>

using namespace std;

#define i64 long long
#define pb push_back

#define MAX_NODES 10

int num_of_unions;

int parent[MAX_NODES];
int rankk[MAX_NODES];

int find(int node)
{
    if(node==parent[node])
    {
        return node;
    }

    parent[node]=find(parent[node]);
    return parent[node];
}

void unionn(int node1,int node2)
{
    int parent1=find(node1);
    int parent2=find(node2);

    if(rankk[parent1]<rankk[parent2])
    {
        parent[parent1]=parent2;
    }
    else if(rankk[parent1]>rankk[parent2])
    {
        parent[parent2]=parent1;
    }
    else
    {
        parent[parent2]=parent1;
        rankk[parent1]+=1;
    }

    printf("%d\t%d\n",node1,node2);

    printf("PARENT\n");
    for(int i=0;i<MAX_NODES;++i)
    {
        printf("%d\t",parent[i]);
    }

    printf("\n");

    printf("RANK\n");
    for(int i=0;i<MAX_NODES;++i)
    {
        printf("%d\t",rankk[i]);
    }

    printf("\n\n\n");
}

int main()
{
    freopen("Disjoint Set.txt","r",stdin);

    int i,j,node1,node2;

    scanf("%d",&num_of_unions);
    //printf("%d\n",num_of_unions);
    for(i=0;i<MAX_NODES;++i)
    {
        parent[i]=i;
    }

    for(i=0;i<num_of_unions;++i)
    {
        scanf("%d %d",&node1,&node2);
        unionn(node1,node2);
    }

    return 0;
}

