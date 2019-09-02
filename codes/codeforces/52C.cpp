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

#define SSIZE 300005

ll n,m;

ll arr[SSIZE];
ll tree[4*SSIZE];
ll lazy[4*SSIZE];

void build(ll node,ll st,ll en)
{
	if(st==en)
	{
		tree[node]=arr[st];
	}
	else
	{
		ll mid=(st+en)/2;
		build(2*node,st,mid);
		build(2*node+1,mid+1,en);
		tree[node]=min(tree[node*2],tree[node*2+1]);
	}
}

void updateRange(ll node,ll st,ll en,ll l,ll r,ll val)
{
	// solving lagging updates
	if(lazy[node]!=0)
	{
		tree[node]+=(lazy[node]);
		if(st!=en)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}

	//out of bounds
	if(st>en || r<st || l>en)
		return;

	//current subarray subrange of given range, update and propagate then return
	if(l<=st && r>=en)
	{
		tree[node]+=(val);
		if(st!=en)
		{
			lazy[node*2]+=val;
			lazy[node*2+1]+=val;
		}
		return;
	}

	int mid=(st+en)/2;
	updateRange(node*2,st,mid,l,r,val);
	updateRange(node*2+1,mid+1,en,l,r,val);
	tree[node]=min(tree[node*2],tree[node*2+1]);

}

ll queryRange(ll node,ll st,ll en,ll l,ll r)
{
	// out of bounds
	if(st>en || r<st || l>en)
		return LLONG_MAX;

	// lagging updates
	if(lazy[node]!=0)
	{
		tree[node]+=(lazy[node]);
		if(st!=en)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l<=st && r>=en)
	{
		return tree[node];
	}
	ll mid=(st+en)/2;
	ll p1=queryRange(node*2,st,mid,l,r);
	ll p2=queryRange(node*2+1,mid+1,en,l,r);
	return min(p1,p2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	build(1,0,n-1);
	cin>>m;
	cin.ignore();
	while(m--)
	{
		ll l,r,val;
		val=LLONG_MIN;
		string s;
		getline(cin,s);
	//	cout<<s<<"\n";
		istringstream iss(s);
		ll num;
		ll hehe=0;
		while(iss>>num)
		{
			if(hehe==0)
			{
				l=num;
			}
			else if(hehe==1)
			{
				r=num;
			}
			else
			{
				val=num;
			}
			hehe++;
		}
		//cout<<l<<" "<<r<<" "<<val<<"\n";
		if(val==LLONG_MIN)
		{
			//rangequery
			if(l<=r)
			{
			    cout<<queryRange(1,0,n-1,l,r)<<"\n";
			}
			else
			{
			    ll p1=queryRange(1,0,n-1,l,n-1);
			    ll p2=queryRange(1,0,n-1,0,r);
			    cout<<min(p1,p2)<<"\n";
			}
		}
		else
		{
			//updatequery
			if(l<=r)
			{
			    updateRange(1,0,n-1,l,r,val);
			}
			else
			{
			    updateRange(1,0,n-1,l,n-1,val);
			    updateRange(1,0,n-1,0,r,val);
			}
		}
	}
    return 0;
}


//252908XL