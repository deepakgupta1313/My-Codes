#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma pack(1)

using namespace std;
using namespace __gnu_pbds;

#define TASK "test"

template<class Node_CItr,
	 class Node_Itr,
	 class Cmp_Fn,
	 class _Alloc>
struct my_node_update
{
    typedef int metadata_type;

    int GCD()
    {
        if(node_begin()==node_end()) return 1;
        else return node_begin().get_metadata();
    }

    void operator()(Node_Itr it, Node_CItr end_it)
    {
        auto l=it.get_l_child();
        auto r=it.get_r_child();
        int left=0,right=0;
        if(l!=end_it) left =l.get_metadata();
        if(r!=end_it) right=r.get_metadata();
        const_cast<int&>(it.get_metadata())=__gcd((*it)->first,__gcd(left,right));
    }

    virtual Node_CItr
    node_begin() const = 0;

    virtual Node_CItr
    node_end() const = 0;
};

tree<
int,
int,
less<int>,
rb_tree_tag,
my_node_update
> me;

int main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>m;
    while(m--)
    {
        char t;
        int q;
        cin>>t>>q;
        if(t=='-') me[q]--;
        else me[q]++;
        if(!me[q]) me.erase(q);
        cout<<me.GCD()<<"\n";
    }
 }
