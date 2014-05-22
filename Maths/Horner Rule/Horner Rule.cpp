#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define PB push_back

vector<int> vect;
int n;

int horner_rule(int x)
{
    int ret=0;

    int i;

    for(i=n-1;i>=0;--i)
    {
        ret=ret*x+vect[i];
    }

    return ret;
}

int main() {

    freopen("Horner Rule.txt","r",stdin);
    int i,j,dum;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&dum);
        vect.PB(dum);
    }

    printf("%d\n",horner_rule(1));
    printf("%d\n",horner_rule(2));
    printf("%d\n",horner_rule(0));


	return 0;
}
