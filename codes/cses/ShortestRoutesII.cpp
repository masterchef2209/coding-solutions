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

double dp[510][510];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,q;
	cin>>n>>m>>q;

	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			dp[i][j]=LLONG_MAX;
			if(i==j)
			{
				dp[i][j]=0;
			}
		}
	}

	for(ll u=0;u<m;u++)
	{
		ll a,b;
		double c;
		cin>>a>>b>>c;
		if(a!=b)
		{
			dp[a][b]=min(c,dp[a][b]);
			dp[b][a]=min(c,dp[a][b]);
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--)
	{
		ll a,b;
		cin>>a>>b;
		if(dp[a][b]==LLONG_MAX)
			cout<<-1<<"\n";
		else
		{
			cout<<fixed<<setprecision(0);
			cout<<dp[a][b]<<"\n";
		}
	}
    return 0;
}


//252908XL