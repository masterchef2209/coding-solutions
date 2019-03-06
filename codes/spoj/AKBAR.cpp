#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

vector< vector<ll> >adj(1000005);
vector< ll >visited(1000005);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,r,m;
		cin>>n>>r>>m;
		set<ll>nodes;
		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
			visited[i]=0;
		}
		for(int u=0;u<r;u++)
		{
			ll a,b;
			cin>>a>>b;
			adj[a].eb(b);
			adj[b].eb(a);
			nodes.insert(a);
			nodes.insert(b);
		}
		int flag1=0;
		for(int i=0;i<m;i++)
		{
			ll k,s;
			set< ll >bag;
			cin>>k>>s;
			queue< pair<ll,ll> >Q;
			Q.push(mp(k,0));
			while(!Q.empty())
			{
				ll curr=Q.front().first;
				ll cdist=Q.front().second;
				Q.pop();
				if(cdist== (s+1) )
					break;
				bag.insert(curr);
				for(auto&nei:adj[curr])
				{
					if(bag.find(nei)==bag.end())
					{
						Q.push(mp(nei,cdist+1));
					}
				}
			}
			for(auto &x:bag)
			{
			    visited[x]++;
			}
		}
		for(auto &x:nodes)
		{
		    if(visited[x]!=1)
		    {
		        flag1=1;
		        break;
		    }
		}
		if(flag1==1)
			cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}