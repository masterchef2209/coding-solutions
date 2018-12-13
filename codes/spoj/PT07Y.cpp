#include<bits/stdc++.h>
using namespace std;

int flag=0;
vector<	int	>g[10005];
vector<	int	>visited(10005,0);

void dfs(int x,int p)
{
	visited[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		if(!visited[g[x][i]])
		{
			dfs(g[x][i],x);
		}
		else
		{
			if(p!=g[x][i])
			{
				flag=1;
				return;
			}
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	if(m!=n-1)
		cout<<"NO"<<endl;
	else
	{
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				dfs(i,0);
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
return 0;
}