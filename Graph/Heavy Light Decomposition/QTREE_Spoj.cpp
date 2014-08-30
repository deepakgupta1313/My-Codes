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


#define root 0
#define N 10100
#define LN 14

VI adj[N],costs[N],indexx[N];
int baseArray[N],ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6];


void make_tree(int cur,int s,int e)
{
    if(s==e-1)
    {
        st[cur]=baseArray[s];
        return;
    }

    int c1=(cur<<1),c2=c1|1,m=(s+e)>>1;
    make_tree(c1,s,m);
    make_tree(c2,m,e);

    st[cur]=(st[c1]>st[c2])?st[c1]:st[c2];
}


void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}


int query_tree(int cur, int s, int e, int S, int E) {
	if(s >= E || e <= S) {
		//qt[cur] = -1;
		return -1;
	}
	if(s >= S && e <= E) {
		//qt[cur] = st[cur];
		return st[cur];
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	int r1=query_tree(c1, s, m, S, E);
	int r2=query_tree(c2, m, e, S, E);
	//qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];

	//return qt[cur];
	return max(r1,r2);
}


int query_up(int u,int v)
{
    if(u==v)
    {
        return 0;
    }

    int uchain,vchain=chainInd[v],ans=-1;

    while(1)
    {
        uchain=chainInd[u];

        if(uchain==vchain)
        {
            if(u==v)
            {
                break;
            }

            int r1=query_tree(1,0,ptr,posInBase[v]+1,posInBase[u]+1);

            if(r1>ans)
            {
                ans=r1;
            }

            break;
        }

        int r2=query_tree(1,0,ptr,posInBase[chainHead[uchain]],posInBase[u]+1);

        if(r2>ans)
        {
            ans=r2;
        }

        u=chainHead[uchain];
        u=pa[0][u];
    }

    return ans;
}


int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}



void query(int u, int v) {
	/*
	 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	int lca = LCA(u, v);
	int ans = query_up(u, lca); // One part of path
	int temp = query_up(v, lca); // another part of path
	if(temp > ans) ans = temp; // take the maximum of both paths
	printf("%d\n", ans);
}


void change(int i, int val) {
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}



void HLD(int curNode, int cost, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;

	int sc = -1, ncost;
	// Loop to find special child
	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, ncost, curNode);
	}

	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}


void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(int i=0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}








int main()
{
    freopen("Text/QTREE.txt","r",stdin);


    	int t;
	scanf("%d ", &t);
	while(t--) {
		ptr = 0;
		int n;
		scanf("%d", &n);
		// Cleaning step, new test case
		for(int i=0; i<n; i++) {
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			for(int j=0; j<LN; j++) pa[j][i] = -1;
		}
		for(int i=1; i<n; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			u--; v--;
			adj[u].push_back(v);
			costs[u].push_back(c);
			indexx[u].push_back(i-1);
			adj[v].push_back(u);
			costs[v].push_back(c);
			indexx[v].push_back(i-1);
		}

		chainNo = 0;
		dfs(root, -1); // We set up subsize, depth and parent for each node
		HLD(root, -1, -1); // We decomposed the tree and created baseArray
		make_tree(1, 0, ptr); // We use baseArray and construct the needed segment tree

		// Below Dynamic programming code is for LCA.
		for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

		while(1) {
			char s[100];
			scanf("%s", s);
			if(s[0]=='D') {
				break;
			}
			int a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='Q') {
				query(a-1, b-1);
			} else {
				change(a-1, b);
			}
		}
	}

}

