		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>

//partially correct

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

#define BSIZE 64

ll n;
ll L,R,L1;

struct node
{
	ll leaf;
	node* child[2];	
};

node* create()
{
	node* ret=new node();
	ret->child[0]=NULL;
	ret->child[1]=NULL;
	ret->leaf=-1;
	return ret;
}

void add(node *root,ll num,ll l)
{
	for(ll i=BSIZE-1;i>=0;i--)
	{
	    ll bb=(num>>i)&1;
		if(root->child[bb]==NULL)
			root->child[bb]=create();
		root=root->child[bb];
	}
	root->leaf=l;
}

ll search(node *root,ll num)
{
    ll ans=0;
    for(ll i=BSIZE-1;i>=0;i--)
	{
		ll ch=(num>>i)&1;
		if(root->child[ch^1]==NULL)
		{
			root=root->child[ch];
		}
		else
		{
		    ans+=(1LL<<(i));
			root=root->child[ch^1];
		}
	}
	L1=root->leaf;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	node *root=create();
	ll xorsum=0;
	ll ans=LLONG_MIN;
	for(ll i=1;i<=n;i++)
	{
		ll tmp;
		cin>>tmp;
		xorsum^=tmp;
		if(i>1)
		{
		    ll val=search(root,xorsum);
		    //cout<<L1<<" "<<i<<" "<<val<<endl;
		    if(val>ans)
		    {
			    ans=val;
			    L=L1;
			    R=i;
		    }
		}
		add(root,xorsum,i);
	}
	cout<<L+1<<" "<<R<<" "<<ans;
    return 0;
}


//252908XL