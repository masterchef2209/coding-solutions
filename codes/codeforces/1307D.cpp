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

ll n,m,k;

vector< vector<ll> >adj(SSIZE);
vector<ll>sp;
ll dis1[SSIZE];
ll disn[SSIZE];

void bfs(ll node,ll dis[])
{
	ll visited[SSIZE]={0};
	queue<ll>Q;
	dis[node]=0;
	Q.push(node);
	visited[node]=1;
	while(!Q.empty())
	{
		ll curr=Q.front();
		Q.pop();
		for(auto &nei:adj[curr])
		{
			if(!visited[nei])
			{
				visited[nei]=1;
				dis[nei]=dis[curr]+1;
				Q.push(nei);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(ll i=0;i<k;i++)
	{
		ll a;
		cin>>a;
		sp.eb(a);
	}
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	bfs(1,dis1);
	bfs(n,disn);
// 	for(ll i=1;i<=n;i++)
// 	{
// 	    cout<<dis1[i]<<" ";
// 	}
// 	cout<<endl;
// 	for(ll i=1;i<=n;i++)
// 	{
// 	    cout<<disn[i]<<" ";
// 	}
// 	cout<<endl;
	vector< pair<ll,ll> >data(k);
	for(ll i=0;i<k;i++)
	{
		data[i]=mp(dis1[sp[i]],sp[i]);
	}
	sort(data.begin(),data.end());
	ll ans=0;
	for(ll i=0;i<(k-1);i++)
	{
		ans=max(ans,min(dis1[data[i].se]+1+disn[data[i+1].se],dis1[data[i+1].se]+1+disn[data[i].se]) );
	}
	cout<<min(ans,disn[1]);
    return 0;
}


//252908XL