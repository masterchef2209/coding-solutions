		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

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
vector<ll>color(SSIZE,0);
vector<ll>dp(SSIZE,0);
vector<ll>ans(SSIZE,0);

void dfs(ll curr,ll par)
{
	dp[curr]=color[curr];
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		dfs(nei,curr);
		dp[curr]+=max(0LL,dp[nei]);
	}
}

void dfs2(ll curr,ll par)
{
	ans[curr]=dp[curr];
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;

		dp[curr]-=max(0LL,dp[nei]);
		dp[nei]+=max(0LL,dp[curr]);
		dfs2(nei,curr);
		dp[nei]-=max(0LL,dp[curr]);
		dp[curr]+=max(0LL,dp[nei]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>color[i];
		if(color[i]==0)
			color[i]=-1;
	}
	for(ll i=0;i<(n-1);i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	dfs(1,-1);
	dfs2(1,-1);
	for(ll i=1;i<=n;i++)
		cout<<ans[i]<<" ";
    return 0;
}


//252908XL