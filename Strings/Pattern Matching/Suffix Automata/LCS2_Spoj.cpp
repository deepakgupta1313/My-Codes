/*
USER: zobayer
TASK: LCS2
ALGO: suffix automaton
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

const int ALPH = 26;
const int MAX = 1 << 17;
const int INF = 0x7f7f7f7f;

typedef struct {
	int len, link, v, w, next[ALPH];
} State;

typedef struct {
	int len, idx;
} Data;

char ss[10][MAX];
int b[MAX << 1], n1, cnt, last;
State st[MAX << 1];
Data a[MAX << 1];
int len[10];

inline int max(const int &a, const int &b) { return a > b ? a : b; }
inline int min(const int &a, const int &b) { return a < b ? a : b; }
inline void setmax(int &a, const int &b) { if(a < b) a = b; }
inline void setmin(int &a, const int &b) { if(a > b) a = b; }
inline bool comp(const Data &p, const Data &q) { return (p.len == q.len)? p.idx > q.idx : p.len > q.len; }
//inline bool comp(const Data &p, const Data &q) { return p.len > q.len; }


void extend(char ch) {
	int nlast = cnt++, p, q;
	st[nlast].len = st[last].len + 1, st[nlast].w = st[nlast].len;
	memset(st[nlast].next, -1, sizeof(int)*ALPH);
	for(p = last; p != -1 && st[p].next[ch] == -1; p = st[p].link) st[p].next[ch] = nlast;
	if(p == -1) st[nlast].link = 0;
	else {
		q = st[p].next[ch];
		if(st[p].len + 1 == st[q].len) st[nlast].link = q;
		else {
			st[cnt].len = st[p].len + 1;
			memcpy(st[cnt].next, st[q].next, sizeof(int)*ALPH);
			st[cnt].link = st[q].link, st[cnt].w = st[cnt].len;
			for(; p != -1 && st[p].next[ch] == q; p = st[p].link) st[p].next[ch] = cnt;
			st[q].link = st[nlast].link = cnt; cnt++;
		}
	}
	last = nlast;
}

void buildDFA(int ppp) {
    int n=len[ppp];
	st[0].link = -1 ,st[0].w = 0, cnt = 1, last = 0;
	memset(st[0].next, -1, sizeof(int)*ALPH);
	for(int i = 0; i < n; i++) extend( ss[ppp][i] - 'a');
}

void lcs(int ppp) {
    int n2=len[ppp];
	int p = 0, len = 0, i, cur;
	for(i = 0; i < n2; i++) {
		cur = ss[ppp][i] - 'a';
		if(st[p].next[cur] == -1) {
			for(; p != -1 && st[p].next[cur] == -1; p = st[p].link);
			if(p == -1) { p = len = 0; continue; }
			len = st[p].len;
		}
		len++; p = st[p].next[cur];
		setmax(st[p].v, len);
	}
	for(i = 0; i < cnt; i++) {
		if(!b[i]) continue;
		setmax(st[st[b[i]].link].v, st[b[i]].v);
	}
	for(i = 0; i < cnt; i++) {
		setmin(st[i].w, st[i].v);
		st[i].v = 0;
	}
}

int main() {
        freopen("Text/LCS2.txt","r",stdin);

	int i, k = 0, m = 0, res = 0;
	while(fgets(ss[k], MAX, stdin)) {
		len[k] = strlen(ss[k])-1;
		if(len[k] < len[m]) m = k;
		k++;
	}
	buildDFA(m);
	n1 = len[m];
	for(i = 0; i < cnt; i++)
	{
		a[i].len = st[i].len;
		a[i].idx = i;
	}

	std::sort(a, a + cnt, comp);

	for(i = 0; i < cnt; i++)
	{
	    //printf("LLLL\t%d\t%d\n",a[i].len,a[i].idx);
		b[i] = a[i].idx;
	}

	for(i = 0; i < k; i++)
	{
		if(i != m) lcs(i);
	}



    for(i = 0; i < cnt; i++)
    {
        setmax(res,st[i].w);
    }


	printf("%d\n", res);

	return 0;
}
