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

vector< vector< pair<ll,ll> > >adj(100005);

ll dist[100005];
ll visited[100005];
ll parent[100005];
void initialize()
{
	for(ll i=0;i<100005;i++)
		dist[i]=LLONG_MAX;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(ll u=0;u<m;u++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		adj[a].eb(b,c);
		adj[b].eb(a,c);
	}
	initialize();
	dist[1]=0;
	priority_queue< pair<ll,ll> , vector< pair<ll,ll> > , greater< pair<ll,ll> > >pq;
	pq.push(mp(0,1));
	visited[1]=1;
	while(!pq.empty())
	{
		ll curr=pq.top().se;
		pq.pop();
		visited[curr]=1;
		for(auto &nei:adj[curr])
		{
			if((dist[curr]+nei.se)<dist[nei.fi] && !visited[nei.fi])
			{
				parent[nei.fi]=curr;
				dist[nei.fi]=dist[curr]+nei.se;
				pq.push(mp(dist[nei.fi],nei.fi));
			}
		}
	}
	if(dist[n]==LLONG_MAX)
	{
	    cout<<-1;
	    return 0;
	}
	ll ans=n;
	vector<ll>pprint;
	pprint.eb(ans);
	while(parent[ans]!=0)
	{
		ans=parent[ans];
		pprint.eb(ans);
	}
	reverse(pprint.begin(),pprint.end());
	for(auto &noo:pprint)
	{
		cout<<noo<<" ";
	}
    return 0;
}


//252908XL