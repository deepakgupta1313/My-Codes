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


double NthRoot(double m_nValue, double index)
{
       double guess,pc;
       pc=50;
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

    //freopen("Text/Nth Root.txt","r",stdin);

    printf("%d root of %d is %lf\n",2,9,NthRoot(9,2));


	return 0;
}
