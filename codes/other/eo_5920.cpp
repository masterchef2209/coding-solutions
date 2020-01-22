/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

struct node
{
	bool leaf;
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
	return ret;
}

void add(node *root,string &s)
{
	for(ll i=0;i<s.size();i++)
	{
		if(root->child[s[i]-'a']==NULL)
		{
			root->child[s[i]-'a']=create();
		}
		root=root->child[s[i]-'a'];
	}
	root->leaf=true;
}

ll ans=0;

void dfs(node *root)
{
	ans++;
	for(ll i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			dfs(root->child[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node *root=create();
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		string su=s.substr(i,s.size()-i);
		add(root,su);
	}
	dfs(root);
cout<<ans-1;
    return 0;
}


//252908XL