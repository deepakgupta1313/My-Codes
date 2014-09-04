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


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

const int CHAR=1;
const int DOT=2;
const int AST=3;
const int PAR=4;

struct Node
{
    int type;
    char ch;
    Node *next;
    Node *child;
    Node *previ;

    Node(int a,char b,Node *c,Node *d)
    {
        type=a;
        ch=b;
        child=c;
        previ=d;
        next=NULL;
    }
};

Node *regexx;


Node *parse(string s)
{
    Node *first=NULL;
    Node *cur=NULL;

    for(int j=0;j<s.length();++j)
    {
        Node *newNode=NULL;

        switch(s[j])
        {
            case '.'    :

                newNode=new Node(DOT,' ',NULL,cur);

                if(cur!=NULL)
                {
                    cur->next=newNode;
                }
                else
                {
                    first=newNode;
                }

                cur=newNode;
                break;


            case '*'    :

                if(cur==NULL)
                {
                    return NULL;
                }

                newNode=new Node(AST,' ',cur,cur->previ);

                if(cur==first)
                {
                    first=newNode;
                }

                if(cur->previ!=NULL)
                {
                    cur->previ->next=newNode;
                }

                cur=newNode;

                break;



            case '('    :

                int k;
                int nParen;
                nParen=0;


                for(k=j;k<s.length();++k)
                {
                    if(s[k]=='(')
                    {
                        ++nParen;
                    }
                    else if(s[k]==')')
                    {
                        --nParen;
                        if(nParen==0)
                        {
                            break;
                        }
                    }
                }

                newNode=new Node(PAR,' ',parse(s.substr(j+1,k-j-1)),cur);

                if(cur!=NULL)
                {
                    cur->next=newNode;
                }
                else
                {
                    first=newNode;
                }

                cur=newNode;
                j=k;
                break;



            default :

                newNode=new Node(CHAR,s[j],NULL,cur);

                if(cur!=NULL)
                {
                    cur->next=newNode;
                }
                else
                {
                    first=newNode;
                }


                cur=newNode;


        }
    }


    return first;
}






class Regex  {
	public:



bool match(string s,Node *n)
{
    //printf("Boool Match\n");
    int pos=0;

    for(;n!=NULL;n=n->next)
    {
        switch(n->type)
        {
            case CHAR   :


                if(pos>=s.length())
                {
                    return false;
                }

                if(s[pos]!=n->ch)
                {
                    return false;
                }

                ++pos;
                break;




            case DOT    :

                if(pos>=s.length())
                {
                    return false;
                }

                ++pos;
                break;



            case AST    :


                for(int j=pos+1;j<=s.length();++j)
                {
                    if(match(s.substr(pos,j-pos),n->child) && match(s.substr(j),n))
                    {
                        return true;
                    }
                }


                break;



            case PAR    :

                for(int j=pos+1;j<=s.length();++j)
                {
                    if(match(s.substr(pos,j-pos),n->child) && match(s.substr(j),n->next))
                    {
                        return true;
                    }
                }

                return false;

        }
    }


    return (pos==s.length());
}



    VS match(VS param0, string param1)
    {
        //printf("VS Match\t%d\n",param0.size());
        regexx=parse(param1);

        VS ret;

        for(int i=0;i<param0.size();++i)
        {
            printf("DD\t%s\n",param0[i].c_str());
            if(match(param0[i],regexx))
            {
                ret.PB(param0[i]);
            }
        }



        return ret;
    }

};

int main()
{

    //freopen("Text/Regex .txt","r",stdin);
    Regex  ss;

    string a[]={"ade","abde","ae","e","abcbccde"};
    string b="(a(bc*)*d)*e";

    VS x;

    arrayToVectorString(a,x,sizeof(a)/sizeof(*a));

    //printf("%d\n",ss.minBarricadeWidth(a,y));
    VS ret=ss.match(x,b);

    printf("RET SIZE\t%d\n",ret.size());

    for(int i=0;i<ret.size();++i)
    {
        printf("%s\n",ret[i].c_str());
    }

	return 0;
}
