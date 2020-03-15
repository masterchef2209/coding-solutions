#include <bits/stdc++.h>

//partial 50/100


using namespace std;
#define ll int
#define SSIZE 500005

ll n;

vector< vector<ll> >adj(SSIZE);
vector<ll>down(SSIZE,1);
vector<ll>up(SSIZE,1);
vector<ll>parent(SSIZE);

void dfs(ll curr,ll par=-1)
{
    parent[curr]=par;
	down[curr]=1;
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		dfs(nei,curr);
		down[curr]=max(down[curr],down[nei]+1);
	}
}

void dfs1(ll curr)
{
    ll par=parent[curr];
    if(par!=-1)
	{
		up[curr]=up[par]+1;
		for(auto &sib:adj[par])
		{
			if(sib==curr || sib==parent[par])
				continue;
			up[curr]=max(up[curr],down[sib]+2);
		}
	}
	for(auto &nei:adj[curr])
	{
	    if(nei==par)
	        continue;
	    dfs1(nei);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<(n-1);i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1);
	dfs1(1);
	for(ll i=1;i<=n;i++)
	{
		cout<<	max(down[i],up[i])	<<"\n";
	}
    return 0;
}