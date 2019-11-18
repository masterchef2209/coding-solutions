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

#define SSIZE 500005

ll n,m,k;

vector< set< pair<ll,ll> > >adj(SSIZE);
vector<ll>weight(SSIZE,0);
vector<ll>dist(SSIZE,LLONG_MAX);
vector<ll>visited(SSIZE,0);
vector<ll>edgeinsptree(SSIZE,0);
vector<ll>whichedgewithnode(SSIZE,-1);
priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > >pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(ll i=0;i<m;i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		adj[a].insert(mp(b,i));
		adj[b].insert(mp(a,i));
		weight[i]=w;
	}
	for(ll i=0;i<k;i++)
	{
		ll s,y;
		cin>>s>>y;
		adj[1].insert(mp(s,i+m));
		adj[s].insert(mp(1,i+m));
		weight[i+m]=y;
	}
	pq.push(mp(0,1));
	dist[1]=0;
	while(!pq.empty())
	{
		ll curr=pq.top().se;
		pq.pop();
		if(visited[curr])
			continue;
		visited[curr]=1;
		for(auto &nei:adj[curr])
		{
			if(!visited[nei.fi])
			{
				ll dist1=dist[curr]+weight[nei.se];
				if(dist1<dist[nei.fi])
				{
					dist[nei.fi]=dist1;
					whichedgewithnode[nei.fi]=nei.se;
					pq.push(mp(dist[nei.fi],nei.fi));
				}
				else if(dist1==dist[nei.fi])
				{
					if(nei.se<whichedgewithnode[nei.fi])
					{
						whichedgewithnode[nei.fi]=nei.se;
					}
				}
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(whichedgewithnode[i]==-1)
			continue;
		edgeinsptree[whichedgewithnode[i]]++;
	}
	ll ans=0;
	for(ll i=m;i<(m+k);i++)
	{
		if(!edgeinsptree[i])
			ans++;
	}
	cout<<ans;
    return 0;
}


//252908XL