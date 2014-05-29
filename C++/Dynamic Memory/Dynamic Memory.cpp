#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define PB push_back

struct element
{
    int key;
    element *next;

    element(int k,element *ne)
    {
        key=k;
        next=ne;
    }
};

element **arr;


int main()
{
    int *a=new int;
    *a=333;

    cout<<*a<<endl;

    arr=new element*[5];

    arr[1]=new element(4,NULL);
    element *ne=new element(6,NULL);
    arr[1]->next=ne;

    printf("%d\n%d\n",arr[1]->key,arr[1]->next->key);


	return 0;
}
