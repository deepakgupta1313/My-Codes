#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef vector<int> VI; typedef vector<VI> VVI;
typedef vector<string> VS; typedef vector<VS> VVS;
typedef signed long long i64; typedef unsigned long long u64;
typedef pair<int, int> PII;

VS tokenize(string s, string ch) {
  VS ret;
  for( int p = 0, p2; p < s.size(); p = p2+1 ) {
    p2 = s.find_first_of(ch, p);
    if( p2 == -1 ) p2 = s.size();
    if( p2-p > 0 ) ret.push_back(s.substr(p, p2-p));
  }
  return ret;
}

VI tokint(string s, string ch) {
  VI ret;
  VS t = tokenize(s, ch);
  for( int i = 0; i < t.size(); i++ )
    ret.push_back(atoi(t[i].c_str()));
  return ret;
}

class HigherMaze {
public:
int navigate(int a, int b, vector <int> c, vector <int> start, vector <int> finish, vector <string> f) {
  int i, j, k, x, y, z, n;
  int ns=1;
  int ret;
  map<VI, int> cton;

  for( i = 0; i < c.size(); i++ ) ns *= c[i];
  VI ast(ns);
  VI cur(c.size(), 0);
  int cp=1;
  x = 0;
  for(;;) {
    cp = (cp*a)%b;
    ast[x] = (cp&1);
    cton[cur] = x++;
    y = c.size()-1;
    while( y >= 0 && cur[y] == c[y]-1 ) {cur[y--] = 0;}
    if( y < 0 ) break;
    cur[y]++;
  }
  VVI con(ns);
  VVI cond(ns);
  x = 0;
  for(;;) {
    for( int dx1 = -1; dx1 <= 1; dx1++ )
    for( int dx2 = -1; dx2 <= 1; dx2++ )
    for( int dx3 = -1; dx3 <= 1; dx3++ )
    for( int dx4 = -1; dx4 <= 1; dx4++ )
    for( int dx5 = -1; dx5 <= 1; dx5++ ) {
      VI cur2 = cur;
      if( c.size() >= 1 ) cur2[0] += dx1;
      if( c.size() >= 2 ) cur2[1] += dx2;
      if( c.size() >= 3 ) cur2[2] += dx3;
      if( c.size() >= 4 ) cur2[3] += dx4;
      if( c.size() >= 5 ) cur2[4] += dx5;
      for( i = 0; i < c.size(); i++ )
        if( cur2[i] < 0 || cur2[i] >= c[i] ) break;
      if( i == c.size() ) {
        z = cton[cur2];
        if( !ast[z] ) {
          con[x].push_back(z);
          cond[x].push_back(1);
        }
      }
    }
    y = c.size()-1;
    while( y >= 0 && cur[y] == c[y]-1 ) {cur[y--] = 0;}
    if( y < 0 ) break;
    cur[y]++;
    x++;
  }
  for( i = 0; i < f.size(); i++ ) {
    VI t = tokint(f[i], " ");
    for( j = 0; j < c.size(); j++ ) cur[j] = t[j];
    x = cton[cur];
    for( j = 0; j < c.size(); j++ ) cur[j] = t[j+c.size()+1];
    y = cton[cur];
    z = t[c.size()];
    con[x].push_back(y);
    cond[x].push_back(z);
  }
  VI d(ns, (1<<31)-1);
  priority_queue<PII> q;
  q.push(PII(0, cton[start]));
  while( !q.empty() ) {
    PII p = q.top(); q.pop();
    x = p.second;
    z = -p.first;
    if( z < d[x] ) d[x] = z; else continue;
    for( i = 0; i < con[x].size(); i++ ) {
      if( ast[con[x][i]] ) continue;
      if( z+cond[x][i] >= d[con[x][i]] ) continue;
      q.push(PII(-(z+cond[x][i]), con[x][i]));
    }
  }
  return d[cton[finish]];
}
};