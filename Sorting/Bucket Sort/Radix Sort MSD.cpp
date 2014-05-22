#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define PB push_back
#define MAXLEN 100


int n;

void radix_sort_msd(vector<string> &vect,int pos)
{
    if(vect.size()<=1)
    {
        return;
    }

    int i,j;

    vector<string> buck[27];

    for(i=0;i<vect.size();++i)
    {
        if((strlen(vect[i].c_str())-1)<pos)
        {
            buck[0].PB(vect[i]);
        }
        else
        {
            buck[((vect[i][pos]-'a')%26)+1].PB(vect[i]);
        }
    }

    vector<string> dumm;
    vect.clear();

    for(i=0;i<buck[0].size();++i)
    {
        vect.PB(buck[0][i]);
    }

    for(i=1;i<27;++i)
    {
        radix_sort_msd(buck[i],pos+1);
        for(j=0;j<buck[i].size();++j)
        {
            vect.PB(buck[i][j]);
        }
    }

}


int main() {

    freopen("Radix Sort MSD.txt","r",stdin);
    vector<string> vect;
    char buff[MAXLEN];

    int i,j;

    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%s",buff);
        vect.PB(string(buff));
    }

    radix_sort_msd(vect,0);

    for(i=0;i<n;++i)
    {
        printf("%s\n",vect[i].c_str());
    }


	return 0;
}
