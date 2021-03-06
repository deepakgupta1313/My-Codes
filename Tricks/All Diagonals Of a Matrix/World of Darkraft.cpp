#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mm[26];
int d[22][22][22][22];
int n,m,nm,a[22][22];
char s[22][22];
void init(int k)
{
    memset(a,0,sizeof(a));
    memset(mm,0,sizeof(mm));
    mm['L'-'A']=2;  mm['R'-'A']=1;  mm['X'-'A']=3;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
		if((i+j)%2==k)
            a[(i-j+nm)/2][(i+j)/2]=mm[s[i][j]-'A'];
    memset(d,-1,sizeof(d));
}
int dp(int u1,int v1,int u2,int v2)
{
    if(d[u1][v1][u2][v2]!=-1)   return d[u1][v1][u2][v2];
    bool vis[520];
    memset(vis,false,sizeof(vis));
    for(int i=u1;i<u2;++i)
    {
        for(int j=v1;j<v2;++j)if(a[i][j])
        {
            if(a[i][j]==1)
                vis[dp(u1,v1,i,v2)^dp(i+1,v1,u2,v2)]=true;
            else if(a[i][j]==2)
                vis[dp(u1,v1,u2,j)^dp(u1,j+1,u2,v2)]=true;
            else
                vis[dp(u1,v1,i,j)^dp(u1,j+1,i,v2)^dp(i+1,v1,u2,j)^dp(i+1,j+1,u2,v2)]=true;
        }
    }
    for(int i=0;i<520;++i)  if(!vis[i]) return d[u1][v1][u2][v2]=i;
    return d[u1][v1][u2][v2]=520;
}

int main()
{
    scanf("%d %d",&n,&m);
    nm=max(n,m);
    for(int i=0;i<n;++i)    scanf("%s",s[i]);
    init(0);
    int res1=dp(0,0,nm+1,nm+1);
    init(1);
    int res2=dp(0,0,nm+1,nm+1);
    if(res1^res2)
        puts("WIN");
    else
        puts("LOSE");
    return 0;
}