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

ll n,m;
vector< vector<ll> >adj(SSIZE);
vector<ll>visited(SSIZE,0);

vector< pair<ll,ll> >biggie(SSIZE);
ll lol=0;
ll frick=LLONG_MIN;
ll frick1=LLONG_MAX;

void dfs(ll curr)
{
	frick=max(frick,curr);
	frick1=min(frick1,curr);
	visited[curr]=1;
	for(auto &nei:adj[curr])
	{
		if(!visited[nei])
			dfs(nei);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	for(ll i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			frick=LLONG_MIN;
			frick1=LLONG_MAX;
			dfs(i);
			biggie[lol]=mp(frick1,frick);
			lol++;
		}
	}
	ll ans=0;
	sort(biggie.begin(),biggie.begin()+lol);
	ll L=biggie[0].fi;
	ll R=biggie[0].se;
	for(ll i=1;i<lol;i++)
	{
		if(biggie[i].fi<R )
		{
		    ans++;
		}
		L=min(L,biggie[i].fi);
		R=max(R,biggie[i].se);
	}
	cout<<ans;
    return 0;
}


//252908XL