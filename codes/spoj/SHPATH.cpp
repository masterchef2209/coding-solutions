#include<bits/stdc++.h>
#define INF           1000000000
using namespace std;

int dist[10005];
bool visited[10005];

int dijkstra(vector< vector < pair<int,int> > >&data,int s,int e)
{
	dist[s]=0;
	priority_queue< pair<int,int> , vector< pair<int,int> >,greater< pair< int,int > > >pq;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		pair<int,int> p=pq.top();
		pq.pop();
		int u=p.second;
		if(visited[u]) continue;
		for(int i=0;i<data[u].size();i++)
		{
			int cost=data[u][i].second;
			int neigh_id=data[u][i].first;
			if(dist[u]+cost<dist[neigh_id])
			{
				dist[neigh_id]=dist[u]+cost;
				pq.push(make_pair(dist[neigh_id],neigh_id));
			}
		}
    visited[u]=true;
    if(u==e) return dist[e];	
	}
return INF;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<10001;i++)
		{
			dist[i]=INF;
			visited[i]=false;
		}
		int n_cities;
		cin>>n_cities;
		vector< vector< pair<int,int> > > data(n_cities+1);
		map<string,int> m;
		for(int i=1;i<=n_cities;i++)
		{
			string name;
			cin>>name;
			m[name]=i;
			int n_neigh;
			cin>>n_neigh;
			for(int j=0;j<n_neigh;j++)
			{
				int neigh_id,cost;
				cin>>neigh_id>>cost;
				data[i].push_back(make_pair(neigh_id,cost));
			}
    }
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			string s,e;
			cin>>s>>e;
			cout<<dijkstra(data,m[s],m[e])<<endl;
			for(int i=0;i<10001;i++)
			{
				dist[i]=INF;
				visited[i]=false;
			}
		}
  }
return 0;
}
