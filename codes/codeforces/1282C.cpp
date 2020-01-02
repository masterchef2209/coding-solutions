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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll m;
	cin>>m;
	while(m--)
	{
		ll n,T,a,b;
		cin>>n>>T>>a>>b;
		vector< pair<ll,ll> >arr(n);
		ll easy=0,hard=0;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i].se;
			if(arr[i].se)
				hard++;
			else
				easy++;
		}
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i].fi;
		}
		sort(arr.begin(),arr.end());
		arr.eb(mp(T+1,0));
		ll peasy=0,phard=0;
		ll ans=0;
		for(ll i=0;i<(ll)arr.size();i++)
		{
			ll reqd=peasy*a+phard*b;
			ll rem=arr[i].fi-1-reqd;
			if(rem>=0)
			{
				ll whee1=min((easy-peasy),rem/a);
				rem-=(whee1*a);
				ll whee2=min((hard-phard),rem/b);
				ans=max(ans,peasy+phard+whee1+whee2);
			}
			ll l=i;
			while(l<(ll)arr.size() && arr[l].fi==arr[i].fi)
			{
				if(arr[l].se)
					phard++;
				else
					peasy++;
				l++;
			}
			i=l-1;
		}
		cout<<ans<<"\n";
	}
    return 0;
}


//252908XL
