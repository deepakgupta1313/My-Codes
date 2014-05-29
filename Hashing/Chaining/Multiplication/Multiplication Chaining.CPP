#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define PB push_back

#define w 8
#define r 3
#define MAX_M 1024

int a,m;

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

element *arr[MAX_M];

int hashh(int key)
{
    int h=((a*key)%(int)pow(2,w))>>(w-r);
    printf("HASH\t%d\n",h);
    return h;
}

void insertt(int num)
{
    printf("Inserting %d\n",num);
    int h=hashh(num);

    element *tp=arr[h];
    arr[h]=new element(num,NULL);
    arr[h]->next=tp;
}


void deletee(int num)
{
    printf("Deleting %d\n",num);

    int h=hashh(num);

    element *pre,*ne;

    pre=NULL;
    ne=arr[h];

    while(ne && ne->key!=num)
    {
        pre=ne;
        ne=ne->next;
    }

    if(ne==NULL)
    {
        printf("Element doesn't exist\n");
    }
    else
    {
        if(pre==NULL)
        {
            arr[h]=NULL;
            delete ne;
        }
        else
        {
            pre->next=ne->next;
            delete ne;
        }
    }
}

void searchh(int num)
{
    printf("Searching %d\n",num);
    int h=hashh(num);

    element *el=arr[h];

    while(el && el->key!=num)
    {
        el=el->next;
    }

    if(el)
    {
        printf("Element exists at %d\n",h);
    }
    else
    {
        printf("Element doesn't exist\n");
    }
}

int main() {

    freopen("Multiplication Chaining.txt","r",stdin);
    int tp;
    m=pow(2,r);

    while(!(a&1))
    {
        a=(rand()%(int)pow(2,w-1))+pow(2,w-1);
    }

    int i,cases,num;
    char c;

    scanf("%d\n",&cases);

    while(cases--)
    {
        //printf("%d\n",cases);

        scanf("%c %d\n",&c,&num);
        printf("%c %d\n",c,num);

        if(c=='I')
        {
            insertt(num);
        }
        else if(c=='D')
        {
            deletee(num);
        }
        else
        {
            searchh(num);
        }

        printf("\n\n");
    }

	return 0;
}
