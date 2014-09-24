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

//#define gc getchar_unlocked
#define gc getchar

inline int readInt()
{
    int ret=0;
    bool negg=false;
    char c;
    c=gc();
    while((c<'0' || c>'9') && c!='-')
    {
        c=gc();
    }
    if(c=='-')
    {
        negg=true;
        c=gc();
    }
    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }
    if(negg)
    {
        ret=-ret;
    }
    return ret;
}

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}




#define MAXN 111111
#define MAXLN 19

int arr[MAXN],ancestors[MAXN][MAXLN],compression_to_values[MAXN],depth[MAXN],max_compression=0;
VI adjacency[MAXN];
map<int,int> values_to_compression;

struct node
{
    int countt;
    node *leftt,*rightt;
    node(int x,node *y,node *z)
    {
        countt=x;
        leftt=y;
        rightt=z;
    }
    node *insertt(int node_leftt,int node_rightt,int w);
};

node *root[MAXN];
node *dummy_node=new node(0,NULL,NULL);
node *node::insertt(int node_leftt,int node_rightt,int w)
{
    if(node_leftt<=w && w<node_rightt)
    {
        if((node_leftt+1)==node_rightt)
        {
            return new node(this->countt+1,dummy_node,dummy_node);
        }
        int midd=(node_leftt+node_rightt)>>1;
        return new node(this->countt+1,this->leftt->insertt(node_leftt,midd,w),this->rightt->insertt(midd,node_rightt,w));
    }
    return this;
}

inline void dfs(int curr,int prevv)
{
    ancestors[curr][0]=prevv;
    depth[curr]=( (prevv==-1) ? 0: (depth[prevv]+1));
    if(prevv==-1)
    {
        root[curr]=dummy_node->insertt(0,max_compression,values_to_compression[arr[curr]]);
    }
    else
    {
        root[curr]=root[prevv]->insertt(0,max_compression,values_to_compression[arr[curr]]);
    }

    for(int i=0;i<adjacency[curr].size();++i)
    {
        if(adjacency[curr][i]!=prevv)
        {
            dfs(adjacency[curr][i],curr);
        }
    }
}

inline int lowest_common_ancestor(int u,int v)
{
    if(depth[u]<depth[v])
    {
        return lowest_common_ancestor(v,u);
    }
    int diff=depth[u]-depth[v];
    for(int i=0;i<MAXLN;++i)
    {
        if((diff>>i)&1)
        {
            u=ancestors[u][i];
        }
    }
    if(u!=v)
    {
        for(int i=MAXLN-1;i>=0;--i)
        {
            if(ancestors[u][i]!=ancestors[v][i])
            {
                u=ancestors[u][i];
                v=ancestors[v][i];
            }
        }
        u=ancestors[u][0];
    }
    return u;
}

inline int ask(node *u,node *v,node *lca,node *parent_lca,int l,int r,int k)
{
    if((l+1)==r)
    {
        return l;
    }
    int countt=u->leftt->countt+v->leftt->countt-lca->leftt->countt-parent_lca->leftt->countt;
    int midd=(l+r)>>1;
    if(countt>=k)
    {
        return ask(u->leftt,v->leftt,lca->leftt,parent_lca->leftt,l,midd,k);
    }
    return ask(u->rightt,v->rightt,lca->rightt,parent_lca->rightt,midd,r,k-countt);
}

int main()
{
    freopen("Text/COT.txt","r",stdin);
    int n,m,i,j,nm1,lnm1;
    n=readPosInt();
    m=readPosInt();
    nm1=n-1;
    lnm1=MAXLN-1;
    for(i=0;i<n;++i)
    {
        arr[i]=readInt();
        values_to_compression[arr[i]];
    }
    max_compression=0;
    for(map<int,int>::iterator it=values_to_compression.begin();it!=values_to_compression.end();++it)
    {
        values_to_compression[it->first]=max_compression;
        compression_to_values[max_compression]=it->first;
        ++max_compression;
    }
    int x,y,z;
    for(i=0;i<nm1;++i)
    {
        x=readPosInt();
        y=readPosInt();
        --x;
        --y;
        adjacency[x].PB(y);
        adjacency[y].PB(x);
    }
    MSET(ancestors,-1);
    dummy_node->leftt=dummy_node->rightt=dummy_node;
    dfs(0,-1);
    for(i=0;i<lnm1;++i)
    {
        for(j=0;j<n;++j)
        {
            if(ancestors[j][i]!=-1)
            {
                ancestors[j][i+1]=ancestors[ancestors[j][i]][i];
            }
        }
    }
    int lca,ans;
    while(m--)
    {
        x=readPosInt();
        y=readPosInt();
        z=readPosInt();
        --x;
        --y;
        lca=lowest_common_ancestor(x,y);
        ans=ask(root[x],root[y],root[lca],(ancestors[lca][0]==-1 ? dummy_node : root[ancestors[lca][0]]),0,max_compression,z);
        printf("%d\n",compression_to_values[ans]);
    }
    return 0;
}
