#include<bits/stdc++.h>
using namespace std;

vector< vector<int> >adj(100007);
vector<int>indegree(100007);
int dp[100007];

void dfs(int i)
{
	if(dp[i]!=0) //it is necessary because it is the dp part so that we do not repeat calculation of sub problems
		return;
	for(int j=0;j<adj[i].size();j++)
	{
		dfs(adj[i][j]);
		dp[i]=max(dp[i],1+dp[adj[i][j]]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		indegree[i]=0;
		dp[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].emplace_back(y);
		indegree[y]++;
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			dfs(i);
			ans=max(ans,dp[i]);
		}
	}
	cout<<ans<<endl;
return 0;
}