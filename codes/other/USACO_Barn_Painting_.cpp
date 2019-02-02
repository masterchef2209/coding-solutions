#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long

vector< vector<int> >adj(100005);
vector< vector<bool> > visited(100005,vector<bool>(4,false));
vector<int> painted(100005,0);

int dp[100005][4];

void dfs(int parent,int i,int col)
{
	if(visited[i][col])	return;
	visited[i][col]=true;
	if(painted[i]!=0 && painted[i]!=col)
	{
		dp[i][col]=0;
		return;
	}
	int c1,c2;
	switch(col)
	{
		case 1:c1=2,c2=3;break;
		case 2:c1=3,c2=1;break;
		case 3:c1=1,c2=2;break;
	}
	dp[i][col]=1;
	for(int j:adj[i])
	{
		if(j!=parent)
		{
			dfs(i,j,c1);
			dfs(i,j,c2);
			dp[i][col]*=(dp[j][c1]+dp[j][c2]);
			dp[i][col]%=MOD;
		}
	}
}

signed main()
{
    ifstream cin("barnpainting.in");
	ofstream cout("barnpainting.out");
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
		dp[i][1]=0;
		dp[i][2]=0;
	}
	for(int u=0;u<n-1;u++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(int u=0;u<k;u++)
	{
		int node,color;
		cin>>node>>color;
		painted[node]=color;
	}
	dfs(-1,1,1);
	dfs(-1,1,2);
	dfs(-1,1,3);
	cout<<(dp[1][1]+dp[1][2]+dp[1][3])%MOD<<endl;
return 0;
}