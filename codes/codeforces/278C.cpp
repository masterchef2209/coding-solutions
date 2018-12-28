#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > bag(110);
vector< vector<int> > graph(110);
vector<int> visited(110,0);

void dfs(int i)
{
	visited[i]=1;
	for(int j=0;j<graph[i].size();j++)
	{
		if(!visited[graph[i][j]])
		{
			dfs(graph[i][j]);
		}
	}
}

int main()
{
	int n,m;
	int ccount=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int q;
		cin>>q;
		if(q==0)
			ccount++;
		while(q--)
		{
			int val;
			cin>>val;
			bag[val].push_back(i);
		}
	}
	if(ccount==n)
	{
		cout<<n<<endl;
		exit(0);
	}
	for(int i=1;i<=m;i++)
	{
		if(!bag[i].empty())
		{
			for(int j=0;j<bag[i].size();j++)
			{
				for(int k=j+1;k<bag[i].size();k++)
				{
					graph[bag[i][j]].push_back(bag[i][k]);
					graph[bag[i][k]].push_back(bag[i][j]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			ans++;
			dfs(i);
		}
	}
	cout<<ans-1<<endl;
return 0;
}