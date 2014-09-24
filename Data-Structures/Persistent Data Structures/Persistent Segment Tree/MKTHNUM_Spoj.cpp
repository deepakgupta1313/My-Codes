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

node *dummy_node=new node(0,NULL,NULL);

node *node::insertt(int node_leftt,int node_rightt,int w)
{
    if(node_leftt<=w && w<node_rightt)
    {
        if(node_leftt+1==node_rightt)
        {
            return new node(this->countt+1,dummy_node,dummy_node);
        }

        int midd=(node_leftt+node_rightt)>>1;

        return new node(this->countt+1,this->leftt->insertt(node_leftt,midd,w),this->rightt->insertt(midd,node_rightt,w));
    }

    return this;
}


int ask(node *u,node *v,int l,int r,int k)
{
    if(l+1==r)
    {
        return l;
    }

    int midd=(l+r)>>1;

    int countt=v->leftt->countt-u->leftt->countt;

    if(countt>=k)
    {
        return ask(u->leftt,v->leftt,l,midd,k);
    }

    return ask(u->rightt,v->rightt,midd,r,k-countt);
}

int arr[MAXN],compression_to_values[MAXN];
node *root[MAXN];
map<int,int> values_to_compression;
int max_compression;

int main()
{
    freopen("Text/MKTHNUM.txt","r",stdin);
    int n,m;

    n=readPosInt();
    m=readPosInt();

    int i;

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

    dummy_node->leftt=dummy_node->rightt=dummy_node;

    for(i=0;i<n;++i)
    {
        root[i]=(i==0?dummy_node:root[i-1])->insertt(0,max_compression,values_to_compression[arr[i]]);

    }

    int x,y,z,ans;

    while(m--)
    {
        //scanf("%d %d %d",&x,&y,&z);
        x=readPosInt();
        y=readPosInt();
        z=readPosInt();
        --x;
        --y;

        ans=ask((x==0?dummy_node:root[x-1]),root[y],0,max_compression,z);

        printf("%d\n",compression_to_values[ans]);

    }


    return 0;
}
