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

#define SSIZE 100005

vector< vector<ll> >adj(SSIZE);
vector<ll>degree(SSIZE,0);
vector<ll>visited(SSIZE,0);
map< pair<ll,ll> ,ll>mm;
vector<ll>ans(SSIZE,0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<(n-1);i++)
	{
		ll a,b;
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		mm[mp(a,b)]=i;
		degree[a]++;
		degree[b]++;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	ll node=-1,val=-1;
	for(ll i=1;i<=n;i++)
	{
		if(degree[i]>val)
		{
			val=degree[i];
			node=i;
		}
	}
	queue<ll>Q;
	Q.push(node);
	visited[node]=1;
	ll lol=0;
	while(!Q.empty())
	{
		ll curr=Q.front();
		Q.pop();
		for(auto &nei:adj[curr])
		{
			if(visited[nei])
				continue;
			ll a=min(curr,nei);
			ll b=max(curr,nei);
			ll index=mm[mp(a,b)];
			ans[index]=lol++;
			visited[nei]=1;
			Q.push(nei);
		}
	}
	for(ll i=0;i<(n-1);i++)
	{
		cout<<ans[i]<<endl;
	}
    return 0;
}


//252908XL