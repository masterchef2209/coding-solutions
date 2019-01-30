#include<bits/stdc++.h>
using namespace std;

vector< vector<int> >adj(100005);
int flag[100005],sum[100005],ma[100005];
void dfs(int i,int par)
{
	if(flag[i])
	{
	    sum[i]=(sum[par]+1);
		ma[i]=max(ma[par],sum[i]);
	}
	else
	{
	    sum[i]=0;
	    ma[i]=ma[par];
	}
	for(auto x:adj[i])
	{
	    if(x!=par)
		    dfs(x,i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>flag[i];
		sum[i]=0;
	}
	for(int u=0;u<n-1;u++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	ma[0]=0;
	sum[0]=0;
	dfs(1,0);
	int count=0;
	vector<int>leaves;
	for(int i=2;i<=n;i++)
	{
		if(adj[i].size()==1)
		{
			leaves.emplace_back(i);
			//cout<<i<<" "<<ma[i]<<endl;
		}
	}
	for(auto i:leaves)
	{
		if(ma[i]<=m)
		{
			count++;
		}
	}
	cout<<count<<endl;
return 0;
}