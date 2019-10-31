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

vector< vector<ll> >adj(610);

long double dp[610];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll s,t;
		cin>>s>>t;
		adj[s].eb(t);
	}
	long double ans=LLONG_MAX;
	for(ll i=0;i<n;i++)
	{
		// we will drop one edge at i
		// i==0 means that we won't drop any edge
		// dpj j=i+1...n is not affected by dpi
		// it is optimal
		dp[n]=0;
		for(ll j=n-1;j>=1;j--)
		{
			long double sum=0.0;
			long double mx=0.0;
			ll num=adj[j].size();
			for(auto &nei:adj[j])
			{
				sum+=dp[nei];
				mx=max(mx,dp[nei]);
			}
			if(j==i && num>=2)
			{
				num--;
				sum-=mx;
			}
			dp[j]=sum/num+1;
		}
		ans=min(ans,dp[1]);
	}
	cout<<fixed<<setprecision(10);
	cout<<ans;
    return 0;
}


//252908XL