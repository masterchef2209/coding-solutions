		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)

//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};

#define fi first
#define se second

#define BSIZE 32

ll n,m;

struct node
{
	bool leaf;
	ll ssize;
	node *child[2];
};
 
node* create()
{
	node* ret=new node();
	ret->child[0]=NULL;
	ret->child[1]=NULL;
	ret->ssize=0;
	return ret;
}
 
void add(node* root,ll num)
{
	for(ll i=BSIZE-1;i>=0;i--)
	{
		ll nn=(num>>i)&1;
		if(root->child[nn]==NULL)
			root->child[nn]=create();
		root=root->child[nn];
	}
	root->leaf=true;
	root->ssize=1;
}

void addf(node *root)
{
    if(root->child[0]==NULL && root->child[1]==NULL)
        return;
    if(root->child[0]!=NULL)
    {
        addf(root->child[0]);
        root->ssize+=((root->child[0])->ssize);
    }
    if(root->child[1]!=NULL)
    {
        addf(root->child[1]);
        root->ssize+=((root->child[1])->ssize);
    }
}

ll ans=-1;

void query(node* root,ll val,ll pos,ll cc)
{
    if(pos<0)
        return;
    if((root->ssize)==(1LL<<(pos+1)))
    {
        return;
    }
    ll fl=(cc>>pos)&1LL;
	if(ans!=-1)
		return;
	if(root->child[0^fl]==NULL)
	{
		ans=val;
		return;
	}
	if(ans!=-1)
		return;
	query(root->child[0^fl],val,pos-1,cc);
	if(ans!=-1)
		return;
	if(root->child[1^fl]==NULL)
	{
		ans=(val+(1LL<<pos));
		return;
	}
	if(ans!=-1)
		return;
	query(root->child[1^fl],val+(1LL<<pos),pos-1,cc);
	if(ans!=-1)
		return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node *root=create();
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		ll tmp;
		cin>>tmp;
		add(root,tmp);
	}
	addf(root);
	ll cc=0;
	for(ll i=0;i<m;i++)
	{
		ll x;
		cin>>x;
		ans=-1;
		cc^=x;
		query(root,0,BSIZE-1,cc);
		cout<<ans<<endl;
	}
    return 0;
}


//252908XL

/*
comments:-
we can find mex by creating xortrie and try to make the smallest number which can't be extended till the root. One important optimization is that at each node we can store the number of leaves in its subtree and compare it with (1LL<<pos), we can know that if given subtree is complete and thus we not need to traverse down this subtree and we can just skip checking this subtree.
In this problem we are not modifying the initial tree rathar taking query as prefix xor of all queries till present moment. In our mex trie whenever we have bit set for a level the meaning of 0 and 1 edges are flipped for that level.
*/
