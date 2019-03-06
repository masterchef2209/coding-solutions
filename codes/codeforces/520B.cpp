#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
#define INF (ll)10e7+9

ll dist[10005];
ll visited[10005];

void djikstra(ll source,ll sink)
{
	 priority_queue< pair<ll,ll>, vector< pair<ll,ll> > , greater< pair<ll,ll> > >pq;
	 pq.push(mp(0,source));
	 dist[source]=0;
	 while(!pq.empty())
	 {
	 	pair< ll,ll > u=pq.top();
	 	pq.pop();
	 	
	 	if(visited[u.second]==1)
	 	    continue;
	 	
	 	if(u.second==sink)
	 	    break;
	 	
	 	if(u.second<=0 || u.second>10000)
	 		continue;
	 	
	 	
	 	visited[u.second]=1;
	 	if(dist[u.second-1]>dist[u.second]+1)
	 	{
	 		dist[u.second-1]=dist[u.second]+1;
	 		pq.push( mp(dist[u.second-1],u.second-1) );
	 	}
	 	if(2*u.second>10000)
	 		continue;
	 	if(dist[2*u.second]>dist[u.second]+1)
	 	{
	 		dist[2*u.second]=dist[u.second]+1;
	 		pq.push( mp(dist[2*u.second],2*u.second) );
	 	}
	 }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll a,b;
	cin>>a>>b;
	for(int i=1;i<=10000;i++)
	{
		dist[i]=INF;
		visited[i]=0;
	}
	djikstra(a,b);
	cout<<dist[b]<<endl;
    return 0;
}