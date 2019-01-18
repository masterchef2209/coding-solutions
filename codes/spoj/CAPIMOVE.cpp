#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long ntop[n+1];
		map<long long,int>pton;
		set<long long>pop;
		vector< vector<int> >tree(n+1);
		for(int u=1;u<=n;u++)
		{
			cin>>ntop[u];
			pton[ntop[u]]=u;
			pop.insert(ntop[u]);
		}
		for(int u=0;u<n-1;u++)
		{
			int v,u1;
			cin>>v>>u1;
			tree[v].emplace_back(u1);
			tree[u1].emplace_back(v);
		}
		for(int i=1;i<=n;i++)
		{
			pop.erase(ntop[i]);
			for(int j=0;j<tree[i].size();j++)
			{
				pop.erase(ntop[tree[i][j]]);
			}
			if(pop.empty())
			{
				cout<<0<<" ";
			}
			else
				cout<< pton[*pop.rbegin()] <<" ";
			pop.insert(ntop[i]);
			for(int j=0;j<tree[i].size();j++)
			{
				pop.insert(ntop[tree[i][j]]);
			}
		}
		cout<<endl;
	}
return 0;
}