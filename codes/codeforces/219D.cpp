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

ll n;

set< pair<ll,ll> >dedges;
vector< vector<ll> >adj(SSIZE);
vector<ll>visited(SSIZE,0);

ll totalulti=0;
ll dp[SSIZE];

ll ans=LLONG_MAX;

void dfs(ll curr)
{
	visited[curr]=1;
	for(auto &nei:adj[curr])
	{
		if(visited[nei])
			continue;
		if(dedges.find(mp(curr,nei))==dedges.end())
		{
			totalulti++;
		}
		dfs(nei);
	}
}

void dfs1(ll curr,ll ccount,ll ulti)
{
	visited[curr]=1;
	dp[curr]=totalulti-2*ulti+ccount;
	ans=min(ans,dp[curr]);
	for(auto &nei:adj[curr])
	{
		if(visited[nei])
			continue;
		ll hehe=0;
		if(dedges.find(mp(curr,nei))==dedges.end())
		{
			hehe=1;
		}
		dfs1(nei,ccount+1,ulti+hehe);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<(n-1);i++)
	{
		ll a,b;
		cin>>a>>b;
		dedges.insert(mp(a,b));
		adj[a].eb(b);
		adj[b].eb(a);
	}
	dfs(1);
	for(ll i=0;i<=n;i++)
	{
		visited[i]=0;
	}
	dfs1(1,0,0);
	cout<<ans<<"\n";
	for(ll i=1;i<=n;i++)
	{
		if(dp[i]==ans)
		{
			cout<<i<<" ";
		}
	}
    return 0;
}


//252908XL