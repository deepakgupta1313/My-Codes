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


#define MAXX 10002

struct trie
{
    int cnt_end;
    struct trie *dot,*dash;
};

int len;
char inp[MAXX],dict[MAXX][22];
int ways[MAXX];

struct trie *root;

string mat[26]={".-","-...","-.-.","-..",
				".","..-.","--.","....",
				"..",".---","-.-",".-..",
				"--","-.","---",".--.",
				"--.-",".-.","...","-",
				"..-","...-",".--","-..-",
				"-.--","--.."};


void init(trie * &tmp)
{
    tmp=new trie;
    tmp->cnt_end=0;
    tmp->dash=tmp->dot=NULL;
}

void add_word(char seq[])
{
    trie *prs=root;
    trie *tmp;

    int ln=strlen(seq);

    for(int alll=0;alll<ln;++alll)
    {
        int lr=seq[alll]-'A';

        for(int addd=0;addd<mat[lr].size();++addd)
        {
            if(mat[lr][addd]=='.')
            {
                if(prs->dot==NULL)
                {
                    init(tmp);
                    prs->dot=tmp;
                }
                prs=prs->dot;
            }
            else
            {
                if(prs->dash==NULL)
                {
                    init(tmp);
                    prs->dash=tmp;
                }

                prs=prs->dash;
            }
        }
    }

    ++(prs->cnt_end);
}


int count_word()
{
    MSET(ways,0);

    ways[len]=1;

    trie *srch;

    for(int ps=len-1;ps>=0;--ps)
    {
        srch=root;

        for(int inc=ps;inc<len && srch;++inc)
        {
            char ch=inp[inc];

            if(ch=='.')
            {
                srch=srch->dot;
            }
            else
            {
                srch=srch->dash;
            }

            if(srch && srch->cnt_end)
            {
                ways[ps]+=srch->cnt_end*ways[inc+1];
            }
        }
    }

    return ways[0];
}


int main()
{
    freopen("Text/MORSE.txt","r",stdin);

    int cases,n;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%s %d",inp,&n);

        len=strlen(inp);

        init(root);

        for(int i=0;i<n;++i)
        {
            scanf("%s",dict[i]);
            add_word(dict[i]);
        }

        printf("%d\n",count_word());
    }

    return 0;
}
