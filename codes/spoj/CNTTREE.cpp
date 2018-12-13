#include<bits/stdc++.h>
using namespace std;
//some doubts in code
int n,k;

map<int,long> count_trees(int node,int dad,int depth,vector< vector<int> >&adj)
{
	map<int,long> m,m_sub,temp;

	if(depth==0)
	{
		m[0]=1;
		return m;
	}
	for(auto x: adj[node])
	{
		if(x==dad)
			continue;
		m_sub=count_trees(x,node,depth-1,adj);
		for(auto it1:m_sub)
		{
			for(auto it2:m)
			{
				if(it1.first+1+it2.first<=k)
				{
					temp[max(it1.first+1,it2.first)]+=it1.second*it2.second;
				}
			}
		}
		for(auto it:temp)
		{
			m[it.first]+=it.second;
		}
		for(auto it:m_sub)
		{
			m[it.first+1]+=it.second;
		}
		temp.clear();
	}
	m.insert({0,1});
return m;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector< vector<int> > adj(n);
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		long long ans=0;
		stack< pair<int,int> > s;
		s.push({0,0});
		int node,dad;
		while(!s.empty())
		{
			node=s.top().first;
			dad=s.top().second;
			s.pop();

			auto no_of_trees=count_trees(node,dad,k,adj);

			for(auto x:no_of_trees)
			{
				ans+=x.second;
			}

			for(auto neigh:adj[node])
			{
				if(neigh!=dad)
				{
					s.push({neigh,node});
				}
			}
		}
		cout<<ans<<endl;
	}
return 0;
}