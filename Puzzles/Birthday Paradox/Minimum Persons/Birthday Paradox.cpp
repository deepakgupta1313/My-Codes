#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>

using namespace std;

#define PB push_back

int birthday_paradox(double prob,int days)
{
    return ceil((1+sqrt(1+8*log(1/prob)*days))/2);
}


int main()
{

    freopen("Birthday Paradox.txt","r",stdin);
    int i,j,cases;

    int days;
    double prob;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%lf %d",&prob,&days);
        printf("Minimum number of people required so that atleast 2 have bday on same date with probability %lf in year of %d days is %d\n\n",prob,days,birthday_paradox(prob,days));
    }

	return 0;
}
