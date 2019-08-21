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

#define SIZE 300005

ll arr[SIZE];
ll query[SIZE];
ll mmax[SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	ll q;
	cin>>q;
	for(ll u=1;u<=q;u++)
	{
		ll st;
		cin>>st;
		if(st==1)
		{
			ll pos,val;
			cin>>pos>>val;
			arr[pos]=val;
			query[pos]=u;
		}
		else
		{
			ll val;
			cin>>val;
			mmax[u]=val;
		}
	}
	for(ll i=q;i>=1;i--)
	{
		mmax[i]=max(mmax[i],mmax[i+1]);
	}
	for(ll i=1;i<=n;i++)
	{
		cout<<max(arr[i],mmax[query[i]+1])<<" ";
	}
    return 0;
}


//252908XL