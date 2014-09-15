#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long double ld;
typedef long long ll;
template <class T> T MIN(T a, T b) {return a < b? a : b;}
template <class T> T MAX(T a, T b) {return b < a? a : b;}
template <class T> T ABS(T a) {return MAX(a, -a);}

string toString(ld d, int precision=-1) {ostringstream out; if (precision != -1) {out.precision(precision); out.setf(ios::fixed);} out << d; return out.str();}
string toString(ll n) {ostringstream out; out << n; return out.str();}
string toString(int n) {return toString(ll(n));}
ll toInt(string s) {istringstream in(s); ll n; in >> n; return n;}
ld toDouble(string s) {istringstream in(s); ld d; in >> d; return d;}
int getNumWords(string s) {int n=0; string t; istringstream in(s); while (in >> t) n++; return n;}
string getWord(string s, int n) {string t; istringstream in(s); while (n >= 0) {n--; in >> t;} return t;}
ll gcd(ll n, ll m) {return m==0? ABS(n) : gcd(m, n%m);}

class Circuits {
  public:
  vector <vector <int> > g;
  vector <vector <int> > cost;
  ll maxDist[100][100];
  ll realBest;

  ll getMaxDist(int src, int dest) {
    if (src == dest) return 0;
    if (maxDist[src][dest] != -1) return maxDist[src][dest];
    ll best = -999999999;

    for (int i = 0; i < g[src].size(); i++) {
      int v = g[src][i];
      ll temp = cost[src][i] + getMaxDist(v,dest);
      if (temp > best)
        best = temp;
    }
    if (best > realBest)
    realBest = best;

    maxDist[src][dest] = best;
    return best;
  }

  int howLong(vector <string> connects, vector <string> costs) {
    realBest = -999999999;
    int i, j;
    g.resize(connects.size());
    cost.resize(connects.size());

    for (i = 0; i < connects.size(); i++) {
      for (j = 0; j < getNumWords(connects[i]); j++) {
        g[i].push_back( toInt(getWord(connects[i], j)));
        cost[i].push_back( toInt(getWord(costs[i], j)));
      }
    }
    for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++) maxDist[i][j] = -1;

    for (i = 0; i < g.size(); i++)
    for (j = 0; j < g.size(); j++)
    getMaxDist(i,j);

    return realBest;
  }
};
