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

ll n,m;

vector< vector< ll > >adj(150005);
vector< ll >visited(150005,0);
vector<ll>degree(150005,0);

ll sum=0,deg=0;

void dfs(ll curr)
{
	visited[curr]=1;
	sum++;
	deg+=degree[curr];
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
	for(ll u=0;u<m;u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
		degree[a]++;
		degree[b]++;
	}
	int flag=0;
	for(ll i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			sum=0;
			deg=0;
			dfs(i);
			ll ed=deg/2;
			ll tem=(sum*(sum-1))/2;
			if(tem!=ed)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
    return 0;
}


//252908XL