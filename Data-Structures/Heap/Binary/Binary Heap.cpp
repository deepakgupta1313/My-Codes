#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

#define PB push_back

void swapp(vector<int> &heapp,int a,int b)
{
    int tp=heapp[a];
    heapp[a]=heapp[b];
    heapp[b]=tp;
}

void flow_up(vector<int> &heapp,int pos)
{
    if(pos<0 || pos>=heapp.size())
    {
        printf("Invalid position to flow up\n");
        return;
    }

    int parent=(pos-1)>>1;

    if(heapp[parent]<heapp[pos])
    {
        swapp(heapp,parent,pos);
        flow_up(heapp,parent);
    }
}

void flow_down(vector<int> &heapp,int pos)
{
    if(pos<0 || pos>=heapp.size())
    {
        printf("Invalid position to flow down\n");
        return;
    }

    int sz=heapp.size();

    int l=(pos<<1)+1;
    int r=l+1;

    int mn=pos;

    if(l<sz && heapp[mn]>heapp[l])
    {
        mn=l;
    }

    if(r<sz && heapp[mn]>heapp[r])
    {
        mn=r;
    }

    if(mn!=pos)
    {
        swapp(heapp,pos,mn);
        flow_down(heapp,mn);
    }
}




void decrease_key(vector<int> &heapp,int pos,int val)
{
    if(pos<0 || pos>=heapp.size())
    {
        printf("Invalid position to decrease key\n");
        return;
    }
    heapp[pos]-=val;
    flow_up(heapp,pos);
}


void increase_key(vector<int> &heapp,int pos,int val)
{
    if(pos<0 || pos>=heapp.size())
    {
        printf("Invalid position to increase key\n");
        return;
    }

    heapp[pos]+=val;
    flow_down(heapp,pos);
}


void insertt(vector<int> &heapp,int val)
{
    heapp.PB(val);

    int sz=heapp.size();

    flow_up(heapp,sz-1);
}

void deletee(vector<int> &heapp,int pos)
{
    if(pos<0 || pos>=heapp.size())
    {
        printf("Invalid position to deletee\n");
        return;
    }

    int sz=heapp.size();
    swapp(heapp,pos,sz-1);
    heapp.pop_back();
    flow_down(heapp,0);
}

int get_min(vector<int> &heapp)
{
    if(heapp.size()>0)
    {
        return heapp[0];
    }

    printf("Heap is empty, so returning -1\n");
    return -1;
}


int remove_min(vector<int> &heapp)
{
    int ret=-1;
    if(heapp.size()>0)
    {
        ret=heapp[0];
        deletee(heapp,0);
        return ret;
    }

    printf("Heap is empty, so no min removal and returning -1\n");
    return -1;
}


void build_heap(vector<int> &heapp)
{
    int sz=heapp.size();
    int i,j,l,r,tp;

    for(i=(sz/2)-1;i>=0;--i)
    {
        flow_down(heapp,i);
    }
}

void display(vector<int> &heapp)
{
    int i;

    for(i=0;i<heapp.size();++i)
    {
        printf("%d\t",heapp[i]);
    }
    printf("\n\n\n");
}

void merge_heap(vector<int> &merged,vector<int> &a,vector<int> &b)
{
    int i;

    for(i=0;i<a.size();++i)
    {
        merged.PB(a[i]);
    }

    for(i=0;i<b.size();++i)
    {
        merged.PB(b[i]);
    }

    build_heap(merged);
}

int main()
{
    freopen("Binary Heap.txt","r",stdin);
    int i,j,n,tp;
    vector<int> heapp;

    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
        scanf("%d",&tp);
        heapp.PB(tp);
    }

    build_heap(heapp);

    for(i=n-1;i>=0;--i)
    {
        //remove_min(heapp);

        decrease_key(heapp,i,99);

        display(heapp);
    }

    vector<int> merged;

    merge_heap(merged,heapp,heapp);


	return 0;
}
