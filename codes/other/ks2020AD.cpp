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

#define int long long

ll n,k;

struct node
{
	bool leaf;
	ll val;
	node* child[26];
};

node* create()
{
	node* ret=new node();
	for(ll i=0;i<26;i++)
	{
		ret->child[i]=NULL;
	}	
	ret->leaf=false;
	ret->val=0;
	return ret;
}

void add(node *root,string &s)
{
	for(ll i=0;i<s.size();i++)
	{
		if(root->child[s[i]-'A']==NULL)
		{
			root->child[s[i]-'A']=create();
		}
		root=root->child[s[i]-'A'];
		root->val+=1;
	}
	root->leaf=true;
}

ll ans=0;

void dfs(node *root)
{
	if(root!=NULL)
	{
		ll hehe=(root->val)/k;
		ans+=hehe;
	}
	for(ll i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			dfs(root->child[i]);
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        cout<<"Case #"<<test<<": ";
        ans=0;
        cin>>n>>k;
        node *trie=create();
        for(ll i=0;i<n;i++)
        {
        	string s;
        	cin>>s;
        	add(trie,s);
        }
        dfs(trie);
        cout<<ans;
        cout<<"\n";
    }
    return 0;
}


//252908XL