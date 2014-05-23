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

class Line
{
    private :
        int length;

    public  :
        void setLength(int l);

        friend int getLength(Line l);
};

void Line::setLength(int l)
{
    length=l;
}

int getLength(Line l)
{
    return l.length;
}

int main()
{

    Line l;
    l.setLength(11);
    printf("%d\n",getLength(l));

	return 0;
}
