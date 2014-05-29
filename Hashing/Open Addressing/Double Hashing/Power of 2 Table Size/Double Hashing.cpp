
//          If tabl size is a power of 2, all the positions are considered



#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

#define PB push_back

void insertt(int num);

int filled_no,m;


int *arr;
bool *del;

int hashh2(int key)
{
    int h=key%m;
    if(!(h&1))
    {
        ++h;
    }

    return h;
}

int hashh(int key,int idx)
{
    int h=(key+idx*hashh2(key))%m;
    //printf("HASH\t%d\n",h);
    return h;
}

void inserttRebuild(int num)
{
    printf("Inserting REBUILD %d\n",num);
    int i;

    int h;

    for(i=0;i<m;++i)
    {
        h=hashh(num,i);
        if(arr[h]==0)
        {
            arr[h]=num;
            break;
        }
    }

}


bool needRebuild()
{
    if(filled_no>=((9*m)/10))
    {
        return true;
    }

    return false;
}

void copyy(int *to,int *from,int sz)
{
    int i;
    for(i=0;i<sz;++i)
    {
        to[i]=from[i];
    }
}

void rebuild()
{
    printf("Rebuilding\n\n");
    int *tp=new int[m];
    memset(tp,0,m*sizeof(*tp));

    copyy(tp,arr,m);
    delete[] arr;
    arr=new int[2*m];
    memset(arr,0,2*m*sizeof(*arr));
    int i;

    int tm=m;
    m=2*m;


    for(i=0;i<tm;++i)
    {
        if(tp[i]!=0 && !del[i])
        {
            inserttRebuild(tp[i]);
        }
    }

    delete[] del;
    del=new bool[m];
    memset(del,0,m*sizeof(*del));

    delete[] tp;
}



void insertt(int num)
{
    printf("Inserting %d\n",num);
    int i;
    if(needRebuild())
    {
        rebuild();
    }

    int h;

    for(i=0;i<m;++i)
    {
        h=hashh(num,i);
        if(arr[h]==0 || del[h])
        {
            arr[h]=num;
            ++filled_no;

            del[h]=false;
            break;
        }
    }

}





void deletee(int num)
{
    printf("Deleting %d\n",num);

    int h;
    int i;
    bool foundd=false;

    for(i=0;i<m;++i)
    {
        h=hashh(num,i);
        if(arr[h]==num)
        {
            if(!del[h])
            {
                --filled_no;
                foundd=true;
                del[h]=true;
                break;
            }
        }
        else if(arr[h]==0)
        {
            break;
        }
    }

    if(!foundd)
    {
        printf("Element doesn't exist\n");
    }
}

void searchh(int num)
{
    printf("Searching %d\n",num);
    int h;
    int i;

    bool foundd=false;

    int emp=-1;

    for(i=0;i<m;++i)
    {
        h=hashh(num,i);
        if(arr[h]==num)
        {
            if(!del[h])
            {
                if(emp!=-1)
                {
                    arr[emp]=arr[h];
                    del[h]=true;
                    del[emp]=false;
                }
                foundd=true;
                break;
            }
        }
        else if(!arr[h]==0)
        {
            break;
        }
        else if(emp==-1 && del[h])
        {
            emp=h;
        }
    }

    if(foundd)
    {
        printf("Element found at %d\n",(h+i)%m);
    }
    else
    {
        printf("Element doesn't exist\n");
    }
}

int main() {

    freopen("Double Hashing.txt","r",stdin);

    m=4;
    arr=new int[m];
    del=new bool[m];

    memset(arr,0,m*sizeof(*arr));
    memset(del,0,m*sizeof(*del));

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
