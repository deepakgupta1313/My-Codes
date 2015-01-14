#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define LOCAL 0
#define DEBUG 0
#define NMAX 250100

char used[NMAX];
int p[NMAX];
int N;

void ReadInput() 
{
	int i;
	if (LOCAL) 
	{
		srand(10000);
		N = 250000;
		memset(used, 0, sizeof(used));
		for (i = 1; i <= N; i++) {
			do {
				p[i] = N - i + 1;//1 + (rand() % N);
			} while (used[p[i]]);
			used[p[i]] = 1;
		}
	} 
	else 
	{
		//freopen("x.txt", "r", stdin);
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			scanf("%d", &p[i]);
	}
}

vector<int> child[NMAX];
set<int> numbers;
int lson[NMAX], rson[NMAX], level[NMAX];
int root;

void BuildBST() 
{
	int i, x, y;
	set<int>::iterator it;
	
	root = p[1];
	numbers.insert(root);
	level[root] = 1;

	memset(lson, 0, sizeof(lson));
	memset(rson, 0, sizeof(rson));

	for (i = 2; i <= N; i++) 
	{
		x = y = 0;
		it = numbers.lower_bound(p[i]);
		
		if (it != numbers.end())
			y = *it;
		
		if (it != numbers.begin())
		{
			it--;
			x = *it;
		}

		if (x > 0 && rson[x] == 0) 
		{
			rson[x] = p[i];
			child[x].push_back(p[i]);
			if (DEBUG) fprintf(stderr, "%d -rson-> %d\n", x, p[i]);
			level[p[i]] = level[x] + 1;
		} 
		else if (y > 0 && lson[y] == 0) 
		{
			lson[y] = p[i];
			child[y].push_back(p[i]);
			if (DEBUG) fprintf(stderr, "%d -lson-> %d\n", y, p[i]);
			level[p[i]] = level[y] + 1;
		} 
		else
			exit(1);
	
		numbers.insert(p[i]);
	}
}

long long cnt[NMAX];
int qbfs[NMAX];

void BFS() 
{
	int li, ls, i, j, k;
	qbfs[li = ls = 1] = root;
	while (li <= ls) 
	{
		i = qbfs[li];
		li++;
		for (k = 0; k < child[i].size(); k++) 
		{
			j = child[i][k];
			ls++;
			qbfs[ls] = j;
		}
	}

	if (ls != N) exit(2);

	for (li = N; li >= 1; li--)
	{
		i = qbfs[li];
		cnt[i] = 1;
		for (j = 0; j < child[i].size(); j++)
			cnt[i] += cnt[child[i][j]];
		if (DEBUG) fprintf(stderr, "i=%d: cnt=%lld\n", i, cnt[i]);
	}
}

int qhpd[NMAX][3], lihpd, lshpd;
vector<int> path[NMAX];
int pathp[NMAX], pathpnode[NMAX], nodepath[NMAX], nodepozinpath[NMAX];
int np;

void BuildPath(int rnode, int pathparent, int pathparentnode) {
	np++;
	pathp[np] = pathparent;
	pathpnode[np] = pathparentnode;

	int i = rnode, j, k, nexti;
	path[np].push_back(i);
	nodepath[i] = np;
	nodepozinpath[i] = path[np].size() - 1;

	while (1) 
	{
		nexti = 0;
		for (k = 0; k < child[i].size(); k++) {
			j = child[i][k];
			if (!nexti || cnt[j] > cnt[nexti])
				nexti = j;
		}

		if (!nexti)
			break;

		for (k = 0; k < child[i].size(); k++) 
		{
			j = child[i][k];
			if (j != nexti) 
			{
				lshpd++;
				qhpd[lshpd][0] = j;
				qhpd[lshpd][1] = np;
				qhpd[lshpd][2] = i;
			}
		}
	
		i = nexti;
		path[np].push_back(i);
		nodepath[i] = np;
		nodepozinpath[i] = path[np].size() - 1;
	}

	if (DEBUG) 
	{
		fprintf(stderr, "path %d (pathp=%d pathpnode=%d):", np, pathp[np], pathpnode[np]);
		for (i = 0; i < path[np].size(); i++)
			fprintf(stderr, " %d", path[np][i]);
		fprintf(stderr, "\n");
	}
}

void BuildHPD() 
{
	int i, j, k;
	
	np = 0;
	lihpd = lshpd = 0;
	qhpd[0][0] = root;
	qhpd[0][1] = qhpd[0][2] = 0;

	while (lihpd <= lshpd) 
	{
		BuildPath(qhpd[lihpd][0], qhpd[lihpd][1], qhpd[lihpd][2]);
		lihpd++;
	}
}

#define MAXNODES 2000000

long long sum[MAXNODES], *psum[NMAX];
int upd[MAXNODES], *pupd[NMAX];
int nl[NMAX], nnodes;

void BuildHPDSegTrees() 
{
	int i, j, nextnnodes, l, r;

	for (i = 1, nnodes = 0; i <= np; i++) 
	{
		nl[i] = 1;
		while (nl[i] < path[i].size())
			nl[i] <<= 1;
		
		psum[i] = sum + nnodes;
		pupd[i] = upd + nnodes;
		nextnnodes = nnodes + (2 * nl[i]);
		
		for(j = nl[i]; j < 2 * nl[i]; j++) 
			psum[i][j] = 0;
		
		for(j = nl[i]; j < nl[i] + path[i].size(); j++)
			psum[i][j] = cnt[path[i][j - nl[i]]];
		
		for(j = nl[i] - 1; j >= 1; j--) 
		{
			l = j << 1;
			r = l + 1;
			psum[i][j] = psum[i][l] + psum[i][r];
		}
		
		for(j = 1; j < 2 * nl[i]; j++) 
			pupd[i][j] = 0;
		
		nnodes = nextnnodes;
	}

}

int QP, QMIN, QMAX, QOP, QUPD;
long long QANS;

void IntervalOpSegTree(int node, int li, int ls) 
{
	if (QMIN <= li && ls <= QMAX) 
	{
		if (QOP == 1) 
		{
			pupd[QP][node]--;
			psum[QP][node] -= (ls - li + 1);
		}
		else 
		{
			QANS += psum[QP][node] + (long long) QUPD * (long long) (ls - li + 1);
		}
		return;
	}

	QUPD += pupd[QP][node];

	int lson = node << 1;
	int rson = lson + 1;
	int mid = (li + ls) >> 1;

	if (QMIN <= mid)
		IntervalOpSegTree(lson, li, mid);
	
	if (QMAX > mid)
		IntervalOpSegTree(rson, mid + 1, ls);

	if (QOP == 1)
		psum[QP][node] = psum[QP][lson] + psum[QP][rson] + (long long) (pupd[QP][node]) * (long long) (ls - li + 1);
	
	QUPD -= pupd[QP][node];

}

long long ans[NMAX], scnt, scnt2, scnttmp;

void ComputeAnswers() 
{
	int i, x;
	
	for (scnt = scnt2 = 0, i = 1; i <= N; i++) {
		scnt += cnt[i];
		scnt2 += (cnt[i] * cnt[i]);
	}

	QUPD = 0;
	for (i = N; i >= 1; i--)
	{
		if (DEBUG) fprintf(stderr, "i=%d scnt=%lld scnt2=%lld\n", i, scnt, scnt2);

		ans[i] = scnt * i - scnt2;
		scnt -= level[p[i]];
		scnttmp = 0;

		QP = nodepath[x = p[i]];
		QMIN = 1; QMAX = nodepozinpath[x] + 1;
		
		if (QMIN <= QMAX) 
		{
			QANS = 0; QOP = 2;
			IntervalOpSegTree(1, 1, nl[QP]);
			scnttmp += QANS;
			QOP = 1;
			IntervalOpSegTree(1, 1, nl[QP]);
		}

		x = path[QP][0];

		while (x != root) 
		{
			x = pathpnode[nodepath[x]];

			QP = nodepath[x];
			QMIN = 1; QMAX = nodepozinpath[x] + 1;
			
			QANS = 0; QOP = 2;
			IntervalOpSegTree(1, 1, nl[QP]);
			scnttmp += QANS;
			QOP = 1;
			IntervalOpSegTree(1, 1, nl[QP]);

			x = path[QP][0];
		}
	
		if (DEBUG)
			fprintf(stderr, "i=%d: p[i]=%d scnttmp=%lld\n", i, p[i], scnttmp);
		scnt2 = scnt2 - scnttmp * 2 + level[p[i]];
	}
}

void WriteAnswers() 
{
	int i;
	for (i = 1; i <= N; i++)
		printf("%lld\n", ans[i]);
}

int main() 
{
	ReadInput();
	BuildBST();
	BFS();
	BuildHPD();
	BuildHPDSegTrees();
	ComputeAnswers();
	WriteAnswers();
	return 0;
}
