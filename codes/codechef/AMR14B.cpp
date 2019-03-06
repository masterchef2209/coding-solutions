#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mt(x,y,z) make_tuple(x,y,z)
#define mod 1000000007
double PI=3.1415926535897932384626;
//not accepted
#define INF (1<<29)
ll n,m;
ll dist[20005];
ll visited[20005];
ll visited1[20005];
ll lastAdded[20005];
vector< vector< pair<ll,ll> > > adj(20005);

void dijkstra(ll st)
{
	for(int i=0;i<n;i++)
	{
		dist[i]=INF;
		visited[i]=0;
		lastAdded[i]=INF;
	}
	priority_queue< tuple<ll,ll,ll> ,vector< tuple<ll,ll,ll> > ,greater< tuple<ll,ll,ll> > >pq;
	dist[st]=0;
	lastAdded[st]=0;
	pq.push(mt(0,0,st));
	while(!pq.empty())
	{
		ll u=get<2>(pq.top());
		pq.pop();
		if(visited[u])
			continue;
		for(auto &x: adj[u])
		{
			ll v=x.first;
			ll cost=x.second;
			if(!visited[v] && (dist[u]+cost<dist[v] || (dist[u]+cost==dist[v] && cost<lastAdded[v]) ) )
			{
				dist[v]=dist[u]+cost;
				lastAdded[v]=cost;
				pq.push(mt(dist[v],lastAdded[v],v));
			}
		}
		visited[u]=1;
	}
}

ll prims(ll st)
{
	for(int i=0;i<n;i++)
	{
		visited1[i]=0;
	}
	priority_queue< pair<ll,ll> ,vector< pair<ll,ll> > ,greater< pair<ll,ll> > >pq;
	ll minCost=0;
	pq.push(mp(0,st));
	while(!pq.empty())
	{
		ll u=pq.top().second;
		ll cost=pq.top().first;
		pq.pop();
		if(visited1[u])
			continue;
		visited1[u]=1;
		minCost+=cost;
		for(auto &x:adj[u])
		{
			if(!visited1[x.first])
				pq.push(mp(x.second,x.first));
		}
	}
	for(ll i=0;i<n;i++)
	{
		if(!visited1[i])
		{
			minCost=-2;
			break;
		}
	}
	return minCost;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(ll i=0;i<n;i++)
		{
			adj[i].clear();
		}
		for(ll i=0;i<m;i++)
		{
			ll u,v,w;
			cin>>u>>v>>w;
			adj[u].eb(mp(v,w));
			adj[v].eb(mp(u,w));
		}
		ll newz=prims(0);
		ll aus=0;
		dijkstra(0);
		for(ll i=0;i<n;i++)
		{
			if(lastAdded[i]==INF)
			{
				aus=-1;
				break;
			}
			aus+=lastAdded[i];
		}
		//cout<<newz<<" "<<aus<<endl;
		if(newz==aus)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}