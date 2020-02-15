#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back

ll cnt=0;
ll adj[2003][2003];
ll visited[2003];
vector< vector<ll> >gg(2003);
vector< vector<ll> >gg1(2003);

void dfs(ll curr)
{
	visited[curr]=1;
	cnt++;
	for(auto &nei:gg[curr])
	{
		if(!visited[nei])
			dfs(nei);
	}
}

void dfs1(ll curr)
{
	visited[curr]=1;
	cnt++;
	for(auto &nei:gg1[curr])
	{
		if(!visited[nei])
			dfs1(nei);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			ll tmp;
			cin>>tmp;
			if(i==j)
			{
				adj[i][j]=0;
				continue;
			}
			if(tmp)
			{
				adj[i][j]=1;
				gg[i].eb(j);
				gg1[j].eb(i);
			}
			else
			{
				adj[i][j]=0;
			}
		}
	}
	dfs(0);
	ll hehe=cnt;
	for(ll i=0;i<=n;i++)
		visited[i]=0;
	cnt=0;
	dfs1(0);
	hehe+=cnt;
	if(hehe==(2*n))
	{
		cout<<"YES";
	}
	else
		cout<<"NO";
return 0;
}