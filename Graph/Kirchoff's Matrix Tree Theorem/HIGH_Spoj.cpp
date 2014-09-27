#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iterator>
#include <cctype>
#include <cstring>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <vector>
#include <ctime>
using namespace std;

#define PB push_back
#define PU push
#define PF push_front
#define EM empty()
#define PP pop()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define max 15

typedef pair<int,int> PI;
typedef pair<int,PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;

double mattt[max][max];
long double det;

void determinant_gauss_elimination(int order)
{
        double temp[max][max];
        double factor  , tempx;
        for(int i=1;i<=order;i++)
                for(int j=1;j<=order;j++)
                        temp[i][j] = mattt[i][j];
        det = 1.0;
        for(int i=1;i<=order-1;i++)
        {
                if(temp[i][i] == 0)
                {
                        for(int j=i+1;j<=order;j++)
                        {
                                if(temp[j][i] != 0.0)
                                {
                                        for(int k = i ; k<= order;k++)
                                        {
                                                tempx = temp[i][k];
                                                temp[i][k] = temp[j][k];
                                                temp[j][k] = tempx;
                                        }
                                        det = -det;
                                        break;
                                }

                        }
                }
                if(temp[i][i] == 0.0)
                        det = 0.0;
                if(det!=0.0)
                        for(int j=i+1;j<=order;j++)
                        {
                                if(temp[j][i] != 0)
                                {
                                        factor = (temp[j][i] * 1.0)/temp[i][i];
                                        for(int k = i ; k<=order ;k++)
                                        {
                                                temp[j][k] = temp[j][k] -  factor*temp[i][k];
                                        }
                                }
                        }
        }

        if(det!=0.0)
                for(int i=1;i<=order;i++)
                        det = det*(long double )temp[i][i];
}

int main()
{
    freopen("Text/HIGH.txt","r",stdin);

        int No;
        int degg[max] , grr[max][max];
        for(scanf("%d",&No);No;No--)
        {
                memset(degg,0,sizeof(degg));
                memset(grr,0,sizeof(grr));
                int N,E,from,to;
                scanf("%d%d",&N,&E);
                for(int i=0;i<E;i++)
                {
                        scanf("%d%d",&from,&to);
                        grr[from][to] = 1;
                        grr[to][from] = 1;
                        degg[to]++;degg[from]++;
                }

                for(int i=2;i<=N;i++)
                {
                        for(int j=2;j<=N;j++)
                        {
                                if(i == j)
                                {
                                    mattt[i-1][j-1] = degg[i];
                                }
                                else
                                {
                                        if(grr[i][j])
                                        {
                                            mattt[i-1][j-1] = -1;
                                        }
                                        else
                                        {
                                            mattt[i-1][j-1] = 0;
                                        }
                                }
                        }
                }

                if(N == 1)
                        printf("%d\n",1);
                else
                {
                        determinant_gauss_elimination(N - 1);
                        printf("%.0llf\n",det);
                }
        }
        return 0;
}
