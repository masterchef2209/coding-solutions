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

#define SSIZE 100005

vector< vector<ll> >data(67);

vector< set<ll> >adj(SSIZE);

vector< pair<ll,ll> >edges;

ll bfs(ll a,ll b)
{
	vector<ll>visited(SSIZE,0);
	queue< pair<ll,ll> >Q;
	Q.push(mp(a,0));
	visited[a]=1;
	ll ret=INT_MAX;
	while(!Q.empty())
	{
		ll c=Q.front().fi;
		ll dis=Q.front().se;
		if(c==b)
		{
			ret=dis+1;
			break;
		}
		Q.pop();
		for(auto &n:adj[c])
		{
			if(c==a && n==b)
				continue;
			if(!visited[n])
			{
				visited[n]=1;
				Q.push(mp(n,dis+1));
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		for(ll j=0;j<=64;j++)
		{
			if((arr[i]>>j)&1)
			{
				data[j].eb(i);
			}
		}
	}
	for(ll i=0;i<=64;i++)
	{
		if(data[i].size()>=3)
		{
		    cout<<3;
			return 0;
		}
	}
	for(ll i=0;i<=64;i++)
	{
		for(ll j=0;j<data[i].size();j++)
		{
			for(ll k=j+1;k<data[i].size();k++)
			{
				adj[data[i][j]].insert(data[i][k]);
				adj[data[i][k]].insert(data[i][j]);
                edges.eb(data[i][j],data[i][k]);
			}
		}
	}
	
	ll ans=INT_MAX;

	for(auto &e:edges)
	{
			ans=min(bfs(e.fi,e.se),ans);
	}
	if(ans==INT_MAX)
	    cout<<-1;
	else
	    cout<<ans;
    return 0;
}


//252908XL