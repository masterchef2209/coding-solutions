		/*Read the problem carefully before starting to work on it*/

//not accepted

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

ll n;

ll arr[300505][2];

ll prefix[300505];
ll suffix1[300505];
ll suffix2[300505];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i][0];
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i][1];
	}
	for(ll i=1;i<=n;i++)
	{
		ll sum=0;
		if(i&1)
		{
			sum+=(arr[i][0]*(2*i-2));
			sum+=(arr[i][1]*(2*i-1));
			prefix[i]=prefix[i-1]+sum;
		}
		else
		{
			sum+=(arr[i][1]*(2*i-2));
			sum+=(arr[i][0]*(2*i-1));
			prefix[i]=prefix[i-1]+sum;
		}
	}
	ll toime=0;
	for(ll i=1;i<=n;i++)
	{
		suffix1[i]+=((toime++)*arr[i][0]);
	}
	for(ll i=n;i>=1;i--)
	{
		suffix1[i]+=((toime++)*arr[i][1]);
	}
	for(ll i=n;i>=1;i--)
	{
		suffix1[i]+=suffix1[i+1];
	}
	toime=0;
	for(ll i=1;i<=n;i++)
	{
		suffix2[i]+=((toime++)*arr[i][1]);
	}
	for(ll i=n;i>=1;i--)
	{
		suffix2[i]+=((toime++)*arr[i][0]);
	}
	for(ll i=n;i>=1;i--)
	{
		suffix2[i]+=suffix2[i+1];
	}
	ll ans=0;
	for(ll i=0;i<=n;i++)
	{
		if(i&1)
		{
			ans=max(ans,prefix[i]+suffix2[i+1]);
		}
		else
		{
			ans=max(ans,prefix[i]+suffix1[i+1]);
		}
	}

	cout<<ans;
    return 0;
}


//252908XL