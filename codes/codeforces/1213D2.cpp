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
#define SSIZE 200005


vector< vector<ll> >adj(SSIZE);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		ll tmp=arr[i];
		while(tmp>0)
		{
			adj[tmp].eb(arr[i]);
			tmp>>=1;
		}
		adj[tmp].eb(arr[i]);
	}
	ll pp=LLONG_MAX;
	for(ll i=0;i<SSIZE;i++)
	{
		if(adj[i].size()<k)
			continue;
		sort(adj[i].begin(),adj[i].end());

		ll tem=0;

		for(ll j=0;j<k;j++)
		{
			ll val=adj[i][j];
			while(val>=0 && val!=i)
			{
				tem++;
				val>>=1;
			}
		}
		pp=min(pp,tem);
	}
	cout<<pp;
    return 0;
}


//252908XL