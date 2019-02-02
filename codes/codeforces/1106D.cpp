#include<bits/stdc++.h>
using namespace std;

vector< set<int> >adj(100005);
vector< int > visited(100005,0);

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u!=v)
		{
			adj[u].insert(v);
			adj[v].insert(u);
		}
	}
	priority_queue<int,vector<int>,greater<int> >Q;
	Q.push(1);
	visited[1]=1;
	while(!Q.empty())
	{
		int t=Q.top();
		Q.pop();
		cout<<t<<" ";
		for(auto j=adj[t].begin();j!=adj[t].end();j++)
		{
			if(visited[*j]==0)
			{
				visited[*j]=1;
				Q.push(*j);
			}
		}
	}
	return 0;
}