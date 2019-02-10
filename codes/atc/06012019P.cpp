#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long

int dp[2][100005];

vector< vector<int> >adj(100005);
vector<int>visited(100005,0);

void dfs(int x)
{
	visited[x]=1;
	dp[0][x]=1;
	dp[1][x]=1;
	for(auto &r: adj[x])
	{
		if(!visited[r])
		{
			dfs(r);
			dp[0][x]=(dp[0][x]*dp[1][r])%MOD;
			dp[1][x]=(dp[1][x]*((dp[0][r]+dp[1][r])%MOD) )%MOD;
		}
	}
}

signed main()
{
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n;
	cin>>n;
	for(int u=0;u<n-1;u++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	dfs(1);
	cout<<(dp[0][1]+dp[1][1])%MOD;
return 0;
}