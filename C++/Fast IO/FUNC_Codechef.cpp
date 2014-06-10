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

using namespace std;

#define PB push_back
#define i64 long long


#define MOD 1000000007

//#define gc getchar_unlocked
#define gc getchar


inline i64 readPosLLD()
{
    i64 ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}

inline i64 readLLD()
{
    i64 ret=0;
    bool negg=false;
    char c;
    c=gc();

    while((c<'0' || c>'9') && c!='-')
    {
        //scanf("%c",&c);
        c=gc();
    }

    if(c=='-')
    {
        negg=true;
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    if(negg)
    {
        ret=-ret;
    }

    return ret;
}



inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}

inline int readInt()
{
    int ret=0;
    bool negg=false;
    char c;
    c=gc();

    while((c<'0' || c>'9') && c!='-')
    {
        //scanf("%c",&c);
        c=gc();
    }

    if(c=='-')
    {
        negg=true;
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    if(negg)
    {
        ret=-ret;
    }

    return ret;
}

int n,q;
vector<i64> a;
i64 x;
vector<pair<i64,int> > xs;
int resu[15001];


inline double NthRoot(double m_nValue, double index)
{
       double guess,pc;
       pc=20;
       double mn=0;
       double mx=min(1,(int)m_nValue);
       guess=(mn+mx)/2.0;
       double result = guess;
       double result_next;
       do
       {
           result_next = (1.0/index)*((index-1.0)*result+(m_nValue)/(pow(result,(index-1.0))));
           result = result_next;
           pc--;
       }while(pc>1);
       return result;
}



int main()
{

    freopen("FUNC_Codechef.txt","r",stdin);

    int cases,i,j;
    i64 tl,tp,tq,ans,tr;

    //scanf("%d",&cases);
    cases=readPosInt();

    while(cases--)
    {
        a.clear();
        xs.clear();
        memset(resu,0,sizeof(resu));


        //scanf("%d %d",&n,&q);
        n=readPosInt();
        q=readPosInt();

        for(i=0;i<n;++i)
        {
            //scanf("%lld",&tl);
            tl=readPosLLD();
            a.PB(tl);
        }

        for(i=1;i<=q;++i)
        {
            //scanf("%lld",&x);
            x=readLLD();
            xs.PB(make_pair(x,i-1));
        }

        sort(xs.begin(),xs.end());

        for(i=0;i<q;++i)
        {
            tl=xs[i].first%MOD;
            tl*=a[0];
            tl%=MOD;
            resu[xs[i].second]+=tl;
        }

        for(i=2;i<=n;++i)
        {
            j=0;

            while(j<q)
            {
                tl=NthRoot(xs[j].first,i);
                tq=tl%MOD;
                //roots[xs[j].second][i]=tq;
                tp=tq*a[i-1];
                tp%=MOD;
                resu[xs[j].second]+=tp;
                resu[xs[j].second]%=MOD;

                tr=tl+1;
                tr=pow(tr,i);
                ++j;

                while(j<q && xs[j].first<tr)
                {
                    //roots[xs[j].second][i]=tq;

                    resu[xs[j].second]+=tp;
                    resu[xs[j].second]%=MOD;

                    ++j;
                }
            }
        }

        for(i=0;i<q-1;++i)
        {
           printf("%d ",resu[i]);
        }
        printf("%d\n",resu[i]);

    }

	return 0;
}
