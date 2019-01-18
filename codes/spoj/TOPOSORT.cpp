#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector< vector<int> >adj(n+1);
	vector< int > indegree(n+1,0);
	for(int u=0;u<m;u++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].emplace_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			indegree[adj[i][j]]++;
		}
	}
	priority_queue<int ,vector<int>,greater<int> >pq;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
			pq.push(i);
	}
	vector<int>ans;
	while(!pq.empty())
	{
		int u=pq.top();
		pq.pop();
		ans.emplace_back(u);
		for(int j=0;j<adj[u].size();j++)
		{
			int v=adj[u][j];
			indegree[v]--;
			if(indegree[v]==0)
				pq.push(v);
		}
	}
	if(ans.size()==n)
	{
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	else
	{
		cout<<"Sandro fails.";
	}
return 0;
}