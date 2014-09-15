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
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair



#define INF (1<<30)

struct Node
{
    int key;
    int cnt;
    int priority;

    Node *left,*right;

    Node()
    {
        cnt=0;
        priority=0;
        left=right=NULL;
    }

    Node(int _key)
    {
        cnt=1;
        key=_key;
        priority=rand();
        left=right=NULL;
    }

    Node(int _key,int pr)
    {
        cnt=1;
        key=_key;
        priority=pr;
        left=right=NULL;
    }


};


struct Treap
{
    Node *root;
    Treap(){root = NULL; srand(time(NULL));}

    int TreeSize(Node* T)
    {
        return T==NULL?0:T->cnt;
    }

    void UpdateCnt(Node* &T)
    {
        if(T)
        {
            T->cnt = 1 + TreeSize(T->left) + TreeSize(T->right);
        }
    }


    void LeftRotate(Node* &T)
    {
        Node* temp = T->left;
        T->left = temp->right;
        temp->right = T;
        T = temp;

        UpdateCnt(T->right);
        UpdateCnt(T);
    }

    void RightRotate(Node* &T)
    {
        Node* temp = T->right;
        T->right = temp->left;
        temp->left = T;
        T = temp;

        UpdateCnt(T->left);
        UpdateCnt(T);
    }


    void Insert(Node* &T, int _key)
    {
        if(T == NULL)
        {
            T = new Node(_key);
            return;
        }

        if(T->key > _key)
        {
            Insert(T->left, _key);

            if(T->priority < T->left->priority)
                LeftRotate(T);
        }
        else if(T->key < _key)
        {
            Insert(T->right, _key);

            if(T->priority < T->right->priority)
                RightRotate(T);
        }

        UpdateCnt(T);
    }


    void Insert(int _key)
    {
        Insert(root, _key);
    }


    void Delete(Node* &T, int _key)
    {
        if(T == NULL)
            return;

        if(T->key > _key)
            Delete(T->left, _key);
        else if(T->key < _key)
            Delete(T->right, _key);
        else
        {
            if(T->left && T->right)
            {
                if(T->left->priority > T->right->priority)
                    LeftRotate(T);
                else
                    RightRotate(T);

                Delete(T, _key);
            }
            else
            {
                Node* temp = T;

                if(T->left)
                    T = T->left;
                else
                    T = T->right;

                delete temp;
            }
        }


        UpdateCnt(T);
    }

    void Delete(int _key)
    {
        Delete(root, _key);
    }


    int Count(Node* T, int bound)
    {
        if(T == NULL)
            return 0;

        if(T->key < bound)
            return 1 + TreeSize(T->left) + Count(T->right, bound);

        return Count(T->left, bound);
    }

    int Count(int bound)
    {
        return Count(root,bound);
    }


    int FindKth(Node* T, int k)
    {
        if(TreeSize(T) < k)
            return -INF;

        int sz = 1 + TreeSize(T->left);

        if(sz == k)
            return T->key;

        if(sz < k)
            return FindKth(T->right, k-sz);

        return FindKth(T->left,k);
    }

    int FindKth(int k)
    {
        return FindKth(root, k);
    }

};


int main()
{
     freopen("Text/ORDERSET.txt","r",stdin);

    int Q; scanf("%d",&Q);

    Treap oTreap;

    while(Q--)
    {
        char t[5];
        int p;
        scanf("%s%d",t,&p);

        if(t[0]=='I')
        {
            oTreap.Insert(p);
        }
        else if(t[0]=='D')
        {
            oTreap.Delete(p);
        }
        else if(t[0]=='K')
        {
            int v = oTreap.FindKth(p);

            if(v > -INF)
            {
                printf("%d\n",v);
            }
            else
                puts("invalid");
        }
        else
        {
            int v = oTreap.Count(p);

            printf("%d\n",v);
        }

    }

    return 0;
}


