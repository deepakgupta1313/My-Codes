#include <bits/stdc++.h>

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


#define MAXN 100010
#define MAXM 200010
#define INF 0x3f3f3f3f

int n, vall[MAXN],maxx[MAXN<<2],leftt_maxx[MAXN<<2],rightt_maxx[MAXN<<2];
int lazy_arr[MAXN<<2],summ[MAXN<<2],first_edge[MAXN],num_edges,nxt[MAXM],to[MAXM];
int q[MAXN],parent[MAXN],depth[MAXN],sizee[MAXN],heavy_child[MAXN];
int groupp[MAXN],compressed[MAXN],ct;


void add_edge(int u,int v)
{
    to[num_edges]=v;
    nxt[num_edges]=first_edge[u];
    first_edge[u]=num_edges++;
}

void lazy_down(int par,int l,int r)
{
    if(lazy_arr[par]!=INF)
    {
        int midd=(l+r)>>1;
        int lc=par<<1;
        int rc=lc+1;

        lazy_arr[lc]=lazy_arr[rc]=lazy_arr[par];
        summ[lc]=(midd-l+1)*lazy_arr[par];
        summ[rc]=(r-midd)*lazy_arr[par];

        maxx[lc]=leftt_maxx[lc]=rightt_maxx[lc]=lazy_arr[par]>0?summ[lc]:lazy_arr[par];
        maxx[rc]=leftt_maxx[rc]=rightt_maxx[rc]=lazy_arr[par]>0?summ[rc]:lazy_arr[par];

        lazy_arr[par]=INF;
    }
}


void pull_up(int par,int l,int r)
{
    int midd=(l+r)>>1;
    int lc=par<<1;
    int rc=lc+1;

    summ[par]=summ[lc]+summ[rc];
    maxx[par]=max(max(maxx[lc],maxx[rc]),leftt_maxx[rc]+rightt_maxx[lc]);
    leftt_maxx[par]=max(leftt_maxx[lc],summ[lc]+leftt_maxx[rc]);
    rightt_maxx[par]=max(rightt_maxx[rc],summ[rc]+rightt_maxx[lc]);
}

void update(int nodee,int nl,int nr,int l,int r,int v)
{
    int midd=(nl+nr)>>1;
    int lc=nodee<<1;
    int rc=lc+1;

    if(nl>=l && nr<=r)
    {
        lazy_arr[nodee]=v;
        summ[nodee]=v*(nr-nl+1);
        maxx[nodee]=leftt_maxx[nodee]=rightt_maxx[nodee]=v>0?summ[nodee]:v;
        return;
    }

    lazy_down(nodee,nl,nr);

    if(midd>=l)
    {
        update(lc,nl,midd,l,r,v);
    }

    if(midd+1<=r)
    {
        update(rc,midd+1,nr,l,r,v);
    }

    pull_up(nodee,nl,nr);
}


int searchh(int nodee,int nl,int nr,int l,int r,bool midd_rightt_f,int &ans,int &tot,int &tr,bool rightt_f)
{
    int midd=(nl+nr)>>1;
    int lc=nodee<<1;
    int rc=lc+1;

    if(nl>=l && nr<=r)
    {
        ans=max(ans,maxx[nodee]);
        tr=max(tr,tot+(rightt_f?rightt_maxx[nodee]:leftt_maxx[nodee]));
        tot+=summ[nodee];
        return midd_rightt_f?rightt_maxx[nodee]:leftt_maxx[nodee];
    }

    lazy_down(nodee,nl,nr);

    if(midd>=r)
    {
        return searchh(lc,nl,midd,l,r,0,ans,tot,tr,rightt_f);
    }
    else if(midd+1<=l)
    {
        return searchh(rc,midd+1,nr,l,r,1,ans,tot,tr,rightt_f);
    }
    else
    {
        int lret,rret;

        if(rightt_f)
        {
            rret=searchh(rc,midd+1,nr,l,r,0,ans,tot,tr,rightt_f);
            lret=searchh(lc,nl,midd,l,r,1,ans,tot,tr,rightt_f);
        }
        else
        {
            lret=searchh(lc,nl,midd,l,r,1,ans,tot,tr,rightt_f);
            rret=searchh(rc,midd+1,nr,l,r,0,ans,tot,tr,rightt_f);

        }

        ans=max(ans,lret+rret);

        if(midd_rightt_f)
        {
            return max(rightt_maxx[rc],summ[rc]+lret);
        }
        else
        {
            return max(leftt_maxx[lc],summ[lc]+rret);
        }
    }
}

void initt()
{
    int rear=0;
    q[rear++]=1;
    depth[1]=1;
    parent[1]=0;
    int i,u,j;

    for(i=0;i<rear;++i)
    {
        u=q[i];

        for(j=first_edge[u];j>=0;j=nxt[j])
        {
            if(to[j]==parent[u])
            {
                continue;
            }

            depth[to[j]]=depth[u]+1;
            parent[to[j]]=u;
            q[rear++]=to[j];
        }
    }

    sizee[0]=0;

    for(i=rear-1;i>=0;--i)
    {
        u=q[i];
        heavy_child[u]=0;
        sizee[u]=1;

        for(j=first_edge[u];j>=0;j=nxt[j])
        {
            if(to[j]==parent[u])
            {
                continue;
            }

            sizee[u]+=sizee[to[j]];
            if(sizee[to[j]]>sizee[heavy_child[u]])
            {
                heavy_child[u]=to[j];
            }
        }
    }

    MSET(groupp,0);
    ct=0;

    for(i=0;i<rear;++i)
    {
        u=q[i];
        if(groupp[u])
        {
            continue;
        }

        j=u;

        while(j!=0)
        {
            groupp[j]=u;
            compressed[j]=++ct;
            j=heavy_child[j];
        }
    }


    MSET(lazy_arr,0x3f);

    for(i=1;i<=n;++i)
    {
        update(1,1,n,compressed[i],compressed[i],vall[i]);
    }
}


void query(int u,int v)
{
    int pu=groupp[u],pv=groupp[v],cu,cv,ans,tot,tr;
    cu=cv=ans=0;

    while(pu!=pv)
    {
        if(depth[pu]>depth[pv])
        {
            swap(pu,pv);
            swap(u,v);
            swap(cu,cv);
        }
        tot=tr=0;
        searchh(1,1,n,compressed[pv],compressed[v],0,ans,tot,tr,1);
        ans=max(ans,tr+cv);
        tot=tr=0;

        searchh(1,1,n,compressed[pv],compressed[v],0,ans,tot,tr,0);
        cv=max(tot+cv,tr);
        v=parent[pv];
        pv=groupp[v];
    }

    if(depth[u]>depth[v])
    {
        swap(u,v);
        swap(cu,cv);
    }

    tot=tr=0;
    searchh(1,1,n,compressed[u],compressed[v],0,ans,tot,tr,0);
    ans=max(ans,tr+cu);

    tot=tr=0;
    searchh(1,1,n,compressed[u],compressed[v],0,ans,tot,tr,1);
    ans=max(ans,tr+cv);
    ans=max(ans,cu+tot+cv);
    printf("%d\n",ans);
}


void change(int x,int y,int v)
{
    int px=groupp[x];
    int py=groupp[y];

    while(px!=py)
    {
        if(depth[px]>depth[py])
        {
            swap(x,y);
            swap(px,py);
        }

        update(1,1,n,compressed[py],compressed[y],v);
        y=parent[py];
        py=groupp[y];
    }

    if(depth[x]>depth[y])
    {
        swap(x,y);
    }

    update(1,1,n,compressed[x],compressed[y],v);
}


int main()
{
    freopen("Text/GSS7.txt","r",stdin);

    int x,y,z,fl;
    int u,v;
    int q;

    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",vall+i);
        }

        MSET(first_edge,-1);
        num_edges=0;;

        for(int i=1;i<n;++i)
        {
            scanf("%d %d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }

        initt();


        scanf("%d",&q);

        while(q--)
        {
            scanf("%d %d %d",&fl,&x,&y);
            if(fl==1)
            {
                query(x,y);
            }
            else
            {
                scanf("%d",&z);
                change(x,y,z);
            }
        }
    }





    return 0;
}

