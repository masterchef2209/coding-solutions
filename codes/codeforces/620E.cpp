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

#define SSIZE 400005

ll n,m;
ll color[SSIZE];
vector< vector<ll> >adj(SSIZE);
vector< ll >visited(SSIZE,0);

ll tim=0;

ll value[SSIZE];
ll subsize[SSIZE];
ll t[4*SSIZE];
ll lazy[4*SSIZE];
ll nodtotime[SSIZE];

void build(ll nod,ll tl,ll tr)
{
	if(tl==tr)
	{
		t[nod]=value[tl];
		return;
	}
	ll tm=(tl+tr)/2;
	build(nod*2,tl,tm);
	build(nod*2+1,tm+1,tr);
	t[nod]=t[nod*2]|t[nod*2+1];
}

void push(ll nod)
{
    if(lazy[nod]==0)
        return;
	t[nod*2]=lazy[nod*2]=t[nod*2+1]=lazy[nod*2+1]=lazy[nod];
	lazy[nod]=0;
}

void update(ll nod,ll tl,ll tr,ll l,ll r,ll val)
{
	if(l>r || l>tr || r<tl)
		return;
	if(l<=tl && r>=tr)
	{
		t[nod]=val;
		lazy[nod]=val;
	}
	else
	{
		push(nod);
		ll tm=(tl+tr)/2;
		update(nod*2,tl,tm,l,min(r,tm),val);
		update(nod*2+1,tm+1,tr,max(l,tm+1),r,val);
		t[nod]=t[nod*2]|t[nod*2+1];
	}
}

ll query(ll nod,ll tl,ll tr,ll l,ll r)
{
	if(l>r || l>tr || r<tl)
		return 0;
	if(l<=tl && r>=tr)
	{
		return t[nod];
	}
	push(nod);
	ll tm=(tl+tr)/2;
	return (query(nod*2,tl,tm,l,min(r,tm))|(query(nod*2+1,tm+1,tr,max(tm+1,l),r)));
}

void dfs(ll curr)
{
	visited[curr]=1;
	value[tim]=(1LL<<(color[curr]-1));
	nodtotime[curr]=tim;
	ll tim1=tim;
	tim++;
	for(auto &nei:adj[curr])
	{
		if(!visited[nei])
		{
			dfs(nei);
		}
	}
	subsize[curr]=tim-tim1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>color[i];
	}
	for(ll u=0;u<(n-1);u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	dfs(1);
	build(1,0,n-1);
	while(m--)
	{
		ll typ;
		cin>>typ;
		if(typ==1)
		{
			ll v,c;
			cin>>v>>c;
			ll pp1=nodtotime[v];
			ll pp2=pp1+subsize[v]-1;
			update(1,0,n-1,pp1,pp2,(1LL<<(c-1)));
		}
		else
		{
			ll v;
			cin>>v;
			ll pp1=nodtotime[v];
			ll pp2=pp1+subsize[v]-1;
			ll hehe=query(1,0,n-1,pp1,pp2);
			cout<<__builtin_popcountll(hehe)<<endl;
		}
	}
    return 0;
}


//252908XL