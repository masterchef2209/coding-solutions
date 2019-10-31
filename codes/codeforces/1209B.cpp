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

ll arr[1000007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	string s;
	cin>>s;
	for(ll u=0;u<n;u++)
	{
		ll a,b;
		cin>>a>>b;
		ll hehe=(s[u]-'0');
		for(ll i=0;i<1000007;i++)
		{
		    if(i>=b)
		    {
		        ll val=(i-b)%a;
		        if(val==0)
		        {
		            hehe^=1;
		        }
		    }
		    arr[i]+=hehe;
		}
	}
	ll ans=0;
	for(ll i=0;i<1000007;i++)
	{
		ans=max(ans,arr[i]);
	}
	cout<<ans;
    return 0;
}


//252908XL