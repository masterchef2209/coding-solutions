#include<bits/stdc++.h>
using namespace std;
//uses Kahn;s algorithm for topo sort
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	while(1)
	{
		if(n==0 && m==0)
			break;
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
		queue<int>ans;
		for(int i=1;i<=n;i++)
		{
			if(indegree[i]==0)
				ans.push(i);
		}
		vector<int>P;
		while(!ans.empty())
		{
			int u=ans.front();
			ans.pop();
			P.push_back(u);
			for(int j=0;j<adj[u].size();j++)
			{
				int v=adj[u][j];
				indegree[v]--;
				if(indegree[v]==0)
					ans.push(v);
			}
		}
			for(auto it=P.begin();it!=P.end();it++)
			{
				cout<< *it <<" ";
			}
			cout<<endl;
	cin>>n>>m;
	}
return 0;
}