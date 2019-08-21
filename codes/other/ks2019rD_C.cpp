		/*Read the problem carefully before starting to work on it*/

//partially correct
		
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
	for(ll test=1;test<=t;test++)
	{
		cout<<"Case #"<<test<<": ";
		ll k,n;
		cin>>k>>n;
		vector< pair<ll,ll> >points(n);
		for(ll u=0;u<n;u++)
		{
			cin>>points[u].fi;
		}
		for(ll u=0;u<n;u++)
		{
			cin>>points[u].se;
		}
		ll ans=LLONG_MAX;
		for(ll warehouse=0;warehouse<n;warehouse++)
		{
			ll val=0;
			priority_queue<ll,vector<ll>,greater<ll> >pq;
			for(ll j=0;j<n;j++)
			{
			    ll hehe=0;
				hehe+=points[j].se;
				hehe+=abs(points[j].fi-points[warehouse].fi);
				pq.push(hehe);
			}
			for(ll cry=0;cry<k+1;cry++)
			{
			    val+=(pq.top());
			    pq.pop();
			}
			//cout<<val<<"\n";
			ans=min(ans,val);
		}
		cout<<ans;
		cout<<"\n";
	}
    return 0;
}


//252908XL