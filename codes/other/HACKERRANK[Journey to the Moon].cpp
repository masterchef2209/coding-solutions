#include<bits/stdc++.h>
using namespace std;

vector<int> nodes[100005];
vector<int> visited(100005,0);

int c=0;

void dfs(int i)
{
	visited[i]=1;
	c++;
	for(int j=0;j<nodes[i].size();j++)
	{
		if(!visited[nodes[i][j]])
		{
			dfs(nodes[i][j]);
		}
	}
	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,p;
	long long ans=0;
  vector<int> an;
	cin>>n>>p;
	while(p--)
	{
		int a,b;
		cin>>a>>b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			c=0;
			dfs(i);
      an.push_back(c);
		}
	}
  long long ar1[an.size()];
  ar1[0]=an[0];
  for(int i=1;i<an.size();i++)
  {
    ar1[i]=ar1[i-1]+an[i];
  }
  for(int i=an.size();i>0;i--)
  {
    ans+=(an[i]*ar1[i-1]);
  }
	cout<<ans;
return 0;
}

