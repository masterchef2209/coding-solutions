#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

vector< vector<ll> >adj(100007);
vector<ll>visited(100007,0);

void dfs(int a)
{
	visited[a]=1;
	for(auto &b:adj[a])
	{
		if(!visited[b])
		{
			dfs(b);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int u=0;u<m;u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i])
			continue;
		ans++;
		dfs(i);
	}
	cout<<ans;
    return 0;
}