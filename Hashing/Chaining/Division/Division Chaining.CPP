#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define PB push_back

#define M 1101

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

element *arr[M];

int hashh(int key)
{
    return key%M;
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

    freopen("Division Chaining.txt","r",stdin);

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
