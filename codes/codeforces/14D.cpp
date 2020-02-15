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

#define SSIZE 210

ll n;
vector< vector<ll> >adj(SSIZE);
vector< pair<ll,ll> >edges;
ll ans=0;

ll one,two;

ll a1,b1;
ll dis1=INT_MIN;
ll dis2=INT_MIN;

void dfs(ll curr,ll par,ll av,ll dist)
{
	if(dist>dis1)
	{
		a1=curr;
		dis1=dist;
	}
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		if(nei==av)
			continue;
		dfs(nei,curr,av,dist+1);
	}
}

void dfs1(ll curr,ll par,ll av,ll dist)
{
	if(dist>dis2)
	{
		b1=curr;
		dis2=dist;
	}
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		if(nei==av)
			continue;
		dfs1(nei,curr,av,dist+1);
	}
}

void f()
{
	for(auto &e:edges)
	{
	    dis1=INT_MIN;
	    dis2=INT_MIN;
		ll a=e.fi;
		ll b=e.se;
		dfs(a,-1,b,0);
		dis1=INT_MIN;
		dfs(a1,-1,b,0);
		dfs1(b,-1,a,0);
		dis2=INT_MIN;
		dfs1(b1,-1,a,0);
		ans=max(ans,dis1*dis2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll u=0;u<(n-1);u++)
	{
		ll a,b;
		cin>>a>>b;
		edges.eb(a,b);
		adj[a].eb(b);
		adj[b].eb(a);
	}
	f();
	cout<<ans;
    return 0;
}


//252908XL