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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector< pair<ll,ll> >data;
		data.eb(0,0);
		for(ll i=0;i<n;i++)
		{
			ll x,y;
			cin>>x>>y;
			data.eb(mp(x,y));
		}
		sort(data.begin(),data.end());
		ll fl=0;
		for(ll i=0;i<(data.size()-1);i++)
		{
			if(data[i].se>data[i+1].se)
			{
				fl=1;
				break;
			}
		}
		if(fl)
			cout<<"NO\n";
		else
		{
			string ans("");
			for(ll i=0;i<(data.size()-1);i++)
			{
				ll diff=abs(data[i].se-data[i+1].se);
				ll diff1=abs(data[i].fi-data[i+1].fi);
				string tem(diff,'U');
				string tem1(diff1,'R');
				ans+=tem1;
				ans+=tem;
			}
			cout<<"YES\n";
			cout<<ans<<endl;
		}
	}
    return 0;
}


//252908XL