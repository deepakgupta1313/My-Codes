#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define PB push_back

#define M 1101

int arr[M];

int hashh(int key)
{
    return key%M;
}

void insertt(int num)
{
    printf("Inserting %d\n",num);
    int h=hashh(num);

    if(arr[h]!=0)
    {
        printf("Slot Preoccupied\n");
        return;
    }
    arr[h]=num;
}


void deletee(int num)
{
    printf("Deleting %d\n",num);

    int h=hashh(num);

    if(arr[h]==0 || arr[h]!=num)
    {
        printf("Element doesn't exist\n");
        return;
    }

    arr[h]=0;
}

void searchh(int num)
{
    printf("Searching %d\n",num);
    int h=hashh(num);

    if(arr[h]==0 || arr[h]!=num)
    {
        printf("Element doesn't exist\n");
        return;
    }

    printf("Element exists at %d\n",h);
}

int main() {

    freopen("Simple Modulus Hashing.txt","r",stdin);

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
