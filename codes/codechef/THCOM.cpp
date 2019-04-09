#include <bits/stdc++.h>
using namespace std;
//not accepted
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
typedef long long ll;

#define fi first
#define se second

vector< vector< pair<int,ll> > >adj(3005);
vector<ll> dist(3005,LLONG_MAX);
vector<int> count1(3005,INT_MAX);
vector<int>comp;
vector<int>visited(3005,0);

void dfs(int i)
{
    visited[i]=1;
    for(auto &x:adj[i])
    {
        if(!visited[x.fi])
            dfs(x.fi);
    }
    comp.eb(i);
}

int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	for(int u=0;u<m;u++)
	{
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);
		adj[a].eb(mp(b,c));
	}
	dfs(1);
	dist[1]=0;
	count1[1]=0;
	for(int i=comp.size()-1;i>=0;i--)
	{
		int x=comp[i];
	    //cout<<x<<" "<<dist[x]<<" "<<count1[x]<<endl;
		for(auto &y:adj[x])
		{
			if(dist[y.fi]>dist[x]+y.se)
			{
				dist[y.fi]=dist[x]+y.se;
				count1[y.fi]=count1[x]+1;
			}
		}
	}
	int q;
	scanf("%d",&q);
	ll sum=0;
	while(q--)
	{
		int status;
		scanf("%d",&status);
		if(status==1)
		{
			ll k;
			scanf("%lld",&k);
			sum+=k;
		}
		else if(status==2)
		{
			int y;
			scanf("%d",&y);
			if(dist[y]==LLONG_MAX)
				cout<<"No Path Exists"<<endl;
			else
				cout<< (dist[y]+sum*count1[y])<<endl;
		}
	}
    return 0;
}