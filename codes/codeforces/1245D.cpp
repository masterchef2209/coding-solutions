		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

#define SSIZE 2010

vector< pair<ll,ll> >cities(SSIZE);
ll c[SSIZE];
ll k[SSIZE];
ll visited[SSIZE];
ll ans=0;
vector< vector< pair<ll,ll> > >adj(SSIZE);

vector<ll>lights;
vector< pair<ll,ll> >connections;

ll prims(ll source)
{
    priority_queue< pair<ll,pair<ll,ll> > , vector< pair<ll, pair<ll,ll> > >, greater< pair<ll, pair<ll,ll> > > >pq;
    pq.push(mp(0,mp(source,-1) ));
    ll ret=0;
    while(!pq.empty())
    {
        auto pp=pq.top();
        pq.pop();
        ll curr=pp.se.fi;
        if(visited[curr])
            continue;
        visited[curr]=1;
        ret+=pp.fi;
        if(pp.se.se==-1)
        {}
        else if(pp.se.se==0)
        {
            lights.eb(curr);
        }
        else
        {
            connections.eb(pp.se);
        }
        for(auto &nei:adj[curr])
        {
            if(!visited[nei.fi])
            {
                pq.push(mp(nei.se,mp(nei.fi,curr) ));
            }
        }
    }
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll u=1;u<=n;u++)
	{
		ll x,y;
		cin>>x>>y;
		cities[u].fi=x;
		cities[u].se=y;
	}
	for(ll u=1;u<=n;u++)
	{
		cin>>c[u];
	}
	for(ll u=1;u<=n;u++)
	{
		cin>>k[u];
	}
	for(ll u=1;u<=n;u++)
	{
		for(ll v=u+1;v<=n;v++)
		{
			ll dist=( (k[u]+k[v])*(abs(cities[u].fi-cities[v].fi)+abs(cities[u].se-cities[v].se) ) );
			adj[u].eb(v,dist);
			adj[v].eb(u,dist);
		}
	}
	for(ll i=1;i<=n;i++)
	{
	   adj[0].eb(i,c[i]);
	   adj[i].eb(0,c[i]);
	}
	ans=prims(0);
	cout<<ans<<"\n";
	cout<<(lights.size())<<"\n";
	for(auto &x:lights)
	{
		cout<<x<<" ";
	}
	cout<<"\n";
	cout<<(connections.size())<<"\n";
	for(auto &x:connections)
	{
		cout<<x.fi<<" "<<x.se<<"\n";
	}
    return 0;
}


//252908XL