#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
 
#define vs vector<string>
#define vi vector<int>
#define ll long long
 
int canproc[256][50][50];
 
class Macros { public: vs whichOnes(vs rules, string target) {
int i,j,k,l,d;
int nr=rules.size(),nt=target.size();
 
for(i=0;i<nt;i++) canproc[target[i]][i][i]=1;

for(d=1;d<nt;d++) for(i=0;i<nt;i++) 
{
	j=d+i; if (j<nt) 
	{
		for(k=0;k<nr;k++) for(l=i;l<j;l++) if (canproc[rules[k][2]][i][l] && canproc[rules[k][3]][l+1][j]) canproc[rules[k][0]][i][j]=1;
	}
}
vs ret; char buf[50]; for(i='A';i<='Z';i++) if (canproc[i][0][nt-1]) { sprintf(buf,"%c",i); ret.push_back(buf); } return ret;
}};