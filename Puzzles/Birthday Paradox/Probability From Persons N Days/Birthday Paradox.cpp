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

double birthday_paradox(int n,int days)
{
    int poww=n*(n-1)/2;

    double ret=1-(pow((days-1)/(double)days,poww));

    return ret;
}


int main()
{

    freopen("Birthday Paradox.txt","r",stdin);
    int i,j,cases;

    int days,num;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d",&num,&days);
        printf("Probability of atleast 1 birthday clash is %lf for number of persons %d and days %d\n\n\n",birthday_paradox(num,days),num,days);
    }

	return 0;
}
