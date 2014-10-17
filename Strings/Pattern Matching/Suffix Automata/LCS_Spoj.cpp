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


#define MAXL 250052
#define K 26

struct state
{
    int length,prevv,next[K];
};

state automata[MAXL*2-1];

int sz,last;
char stra[MAXL],strb[MAXL];


void init()
{
    automata[0].prevv=-1;
    MSET(automata[0].next,-1);
    ++sz;
}


void add_char(char next_char)
{
    int nlast=sz++;
    int p,q,clone;

    automata[nlast].length=automata[last].length+1;

    MSET(automata[nlast].next,-1);

    for(p=last;p!=-1 && automata[p].next[next_char]==-1; p=automata[p].prevv)
    {
        automata[p].next[next_char]=nlast;
    }

    if(p==-1)
    {
        automata[nlast].prevv=0;
    }
    else
    {
        q=automata[p].next[next_char];

        if(automata[q].length==automata[p].length+1)
        {
            automata[nlast].prevv=q;
        }
        else
        {
            clone=sz++;
            automata[clone].prevv=automata[q].prevv;
            memcpy(automata[clone].next,automata[q].next,sizeof(automata[clone].next));
            automata[clone].length=automata[p].length+1;

            for(; p!=-1 && automata[p].next[next_char]==q;p=automata[p].prevv)
            {
                automata[p].next[next_char]=clone;
            }

            automata[q].prevv=automata[nlast].prevv=clone;
        }
    }

    last=nlast;
}


int longest_common_substring(char *sa,char *sb)
{
    int i,p,l,best,bestpos;

    init();

    for(i=0;sa[i];++i)
    {
        add_char(sa[i]-'a');
    }

    p=l=best=bestpos=0;

    for(i=0;sb[i];++i)
    {
        if(automata[p].next[sb[i]-'a']==-1)
        {

                for(; p!=-1 && automata[p].next[sb[i]-'a']==-1;p=automata[p].prevv);

                if(p==-1)
                {
                    p=l=0;
                    continue;
                }
                l=automata[p].length;

        }

        p=automata[p].next[sb[i]-'a'];
        ++l;
        if(l>best)
        {
            best=l;
            bestpos=i;
        }
    }

    return best;
}


int main()
{
    freopen("Text/LCS.txt","r",stdin);

    printf("%d\n", longest_common_substring(gets(stra), gets(strb)));

    return 0;
}


