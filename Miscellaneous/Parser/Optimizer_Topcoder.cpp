#ifdef WIN32
#pragma warning(disable:4786 4503)
#endif
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#ifdef WIN32
#define min _cpp_min
#define max _cpp_max
#define i64 __int64
#define u64 unsigned __int64
#else
#define i64 long long
#define u64 unsigned long long
#endif
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef set<int> si;
typedef set<string> ss;
typedef set<char> sc;
typedef pair<int,int> pii;
#ifdef WIN32
#include <conio.h>
#include "..\\utils\\debug.cpp"
#endif

#include <stdarg.h>

template <class T> ostream &operator << (ostream &out, const vector<T> &a);
template <class T> void print(const T &a);
template <class Ta, class Tb> bool eq(const Ta &a, const Tb &b);
vector<int> mkvecint(int n, ...);
vector<string> mkvecstring(int n, ...);


struct expr;
typedef expr* pexpr;
typedef list<pexpr> lpexpr;

#define prod 1
#define sum 2
#define var 3
#define num 4

struct expr
{
  int type;
  string sval;
  double dval;
  lpexpr lval;
};

string s;
int i;

pexpr expr1();
pexpr expr2();
pexpr expr3();

pexpr expr1()
{
    pexpr r=new expr;
    r->type=sum;

    r->lval.push_back(expr2());

    while(i<s.size() && s[i]=='+')
    {
        ++i;
        r->lval.push_back(expr2());
    }

    if(r->lval.size()==1)
    {
        return r->lval.front();
    }

    return r;
}



pexpr expr2()
{
    pexpr r=new expr;
    r->type=prod;

    r->lval.push_back(expr3());

    while(i<s.size() && s[i]=='*')
    {
        ++i;
        r->lval.push_back(expr3());
    }

    if(r->lval.size()==1)
    {
        return r->lval.front();
    }

    return r;
}


pexpr expr3()
{
    if(i<s.size() && s[i]=='(')
    {
        ++i;
        pexpr r=expr1();

        ++i;

        return r;
    }

      string tok;
      while(i<s.size() && isalnum(s[i]))
      {
        tok+=s[i];
        i++;
      }

      pexpr r=new expr;

      int k;
      if(sscanf(tok.c_str(),"%d",&k)==1)
      {
        r->type=num;
        r->dval=k;
      }
      else
      {
        r->type=var;
        r->sval=tok;
      }
      return r;


}



void execsum(pexpr& p)
{
  double dsum=0;
  lpexpr::iterator it;
  for(it=p->lval.begin();it!=p->lval.end();)
    if((*it)->type==num)
    {
      dsum+=(*it)->dval;
      it=p->lval.erase(it);
    }
    else
      it++;
  if(dsum!=0 || p->lval.size()==0)
  {
    pexpr p2=new expr;
    p2->type=num;
    p2->dval=dsum;
    p->lval.push_back(p2);
  }
  if(p->lval.size()==1)
  {
    p=p->lval.front();
  }
}

void execprod(pexpr& p)
{
  double dprod=1;
  lpexpr::iterator it;
  for(it=p->lval.begin();it!=p->lval.end();)
    if((*it)->type==num)
    {
      dprod*=(*it)->dval;
      it=p->lval.erase(it);
    }
    else
      it++;
  if(dprod==0)
  {
    p=new expr;
    p->type=num;
    p->dval=dprod;
    return;
  }
  if(dprod!=1 || p->lval.size()==0)
  {
    pexpr p2=new expr;
    p2->type=num;
    p2->dval=dprod;
    p->lval.push_back(p2);
  }
  if(p->lval.size()==1)
  {
    p=p->lval.front();
  }
}

pexpr optimize(pexpr p)
{
  switch(p->type)
  {
  case sum:
    {
      lpexpr::iterator it,it2;
      pexpr r=new expr;
      r->type=sum;
      for(it=p->lval.begin();it!=p->lval.end();it++)
      {
        *it=optimize(*it);
        switch((*it)->type)
        {
        case sum:
          for(it2=(*it)->lval.begin();it2!=(*it)->lval.end();it2++)
            r->lval.push_back(*it2);
          break;
        default:
          r->lval.push_back(*it);
        }
      }
      execsum(r);
      return r;
    }
  case prod:
    {
      lpexpr::iterator it,it2;
      pexpr r=new expr;
      r->type=prod;
      for(it=p->lval.begin();it!=p->lval.end();it++)
      {
        *it=optimize(*it);
        switch((*it)->type)
        {
        case prod:
          for(it2=(*it)->lval.begin();it2!=(*it)->lval.end();it2++)
            r->lval.push_back(*it2);
          break;
        default:
          r->lval.push_back(*it);
        }
      }
      execprod(r);
      return r;
    }
  default:
    return p;
  }
}










int nops(pexpr p)
{
  int r=0;
  switch(p->type)
  {
  case sum:
    r+=p->lval.size()-1;
    {
      for(lpexpr::iterator it=p->lval.begin();it!=p->lval.end();it++)
        r+=nops(*it);
    }
    break;
  case prod:
    r+=10*(p->lval.size()-1);
    {
      for(lpexpr::iterator it=p->lval.begin();it!=p->lval.end();it++)
        r+=nops(*it);
    }
    break;
  }
  return r;
}


class Optimizer
{
public:
  int reduce(string ex)
  {
    s="";
    for(i=0;i<ex.size();i++)
      if(ex[i]!=' ')
        s=s+ex[i];
    i=0;
    pexpr r=expr1();
    pexpr r2=optimize(r);
    return nops(r2);
  }







  static bool fmain;
static void main(){
  if(fmain) return;
  fmain = true;
  validateExample("1", (new Optimizer())->reduce("  alpha*beta+5*006  "), 11, "reduce(\"  alpha*beta+5*006  \")");
  validateExample("2", (new Optimizer())->reduce("a * b * 00 + 1 * 5"), 0, "reduce(\"a * b * 00 + 1 * 5\")");
  validateExample("3", (new Optimizer())->reduce("dx + a * b * 0 + 1 * c"), 1, "reduce(\"dx + a * b * 0 + 1 * c\")");
  validateExample("4", (new Optimizer())->reduce("5 * (3 + 4 + c) + (a + c) * (c + d)"), 24, "reduce(\"5 * (3 + 4 + c) + (a + c) * (c + d)\")");
  validateExample("5", (new Optimizer())->reduce("9 * ((4 + 4)) * (7) * (3 + 1) + 504"), 0, "reduce(\"9 * ((4 + 4)) * (7) * (3 + 1) + 504\")");
  validateExample("6", (new Optimizer())->reduce("((((aa))))"), 0, "reduce(\"((((aa))))\")");
  validateExample("7", (new Optimizer())->reduce("(1 + 0 * a) * c + (0 + 0 * b) * d"), 0, "reduce(\"(1 + 0 * a) * c + (0 + 0 * b) * d\")");
  validateExample("8", (new Optimizer())->reduce("5 * d + 5 * b"), 21, "reduce(\"5 * d + 5 * b\")");
  validateExample("9", (new Optimizer())->reduce("(a*5)*4+((a+4)+5)"), 12, "reduce(\"(a*5)*4+((a+4)+5)\")");
  validateExample("10", (new Optimizer())->reduce("(a*5)*(b*6)"), 20, "reduce(\"(a*5)*(b*6)\")");
  validateExample("11", (new Optimizer())->reduce("(1)+0+1*(w+6)*1"), 1, "reduce(\"(1)+0+1*(w+6)*1\")");
}
  static void validateExample(string exampleNum, int returned, int expected, string methodInvocation) {
    print(exampleNum);
    print("  ");
    if (!eq(returned,expected)) {
      print("FAIL");
    } else {
      print("SUCCESS");
    }
    print(" ");
    print(methodInvocation);
    print("\tGot:[");
    print(returned);
    print("]\t");
    print("Expected:[");
    print(expected);
    print("]");
    print("\n");
  }


};

bool Optimizer::fmain = false;

template <class T> ostream &operator << (ostream &out, const vector<T> &a){
  int s = a.size();
  for(int i=0; i<s-1; i++)
    out << a[i] << ",";
  if(s>0)
    out << a[s-1];
  return out;
}

template <class T> void print(const T &a){
  cout << a;
}

template <class Ta, class Tb> bool eq(const Ta &a, const Tb &b){
  return (a==b);
}

vector<int> mkvecint(int n, ...){
  vector<int> v(0);
  va_list vl;
  va_start(vl, n);
  for(int i=0; i<n; i++){
    int t = va_arg(vl, int);
    v.push_back(t);
  }
  va_end(vl);
  return v;
}

vector<string> mkvecstring(int n, ...){
  vector<string> v(0);
  va_list vl;
  va_start(vl, n);
  for(int i=0; i<n; i++){
    char *t = va_arg(vl, char *);
    v.push_back(t);
  }
  va_end(vl);
  return v;
}


//#ifdef WIN32

int main()
{
  Optimizer::main();

  return 0;
}
//#endif

// Powered by CodeProcessor
