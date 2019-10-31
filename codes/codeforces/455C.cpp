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
#define SSIZE 300005

ll n,m,q;

vector< vector<ll> >adj(SSIZE);
vector<ll>visited(SSIZE,0);
vector<ll>visited1(SSIZE,0);

stack<ll>st;

ll size[SSIZE];
ll parent[SSIZE];
ll diameter[SSIZE];

ll find_set(ll i)
{
	if(i==parent[i])
		return i;
	return parent[i]=find_set(parent[i]);
}

void union_sets(ll a,ll b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		if(size[a]<size[b])
			swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
		diameter[a]=max({diameter[a],diameter[b],(diameter[a]+1)/2+(diameter[b]+1)/2+1 });
	}
}

ll pre,di;

void dfs(ll i,ll val)
{
	visited[i]=1;
	if(val>di)
	{
		di=val;
		pre=i;
	}
	st.push(i);
	for(auto &j:adj[i])
	{
		if(visited[j]==0)
		{
			dfs(j,val+1);
		}
	}
}

void dfs1(ll i,ll val)
{
	visited1[i]=1;
	if(val>di)
	{
		di=val;
		pre=i;
	}
	for(auto &j:adj[i])
	{
		if(visited1[j]==0)
		{
			dfs1(j,val+1);
		}
	}
}

ll find_diameter(ll i)
{
	pre=i;
	di=0;
	dfs(i,0);
	di=0;
	dfs1(pre,0);
	return di;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>q;
	for(ll u=0;u<m;u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	for(ll i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			ll dd=find_diameter(i);
			ll c=st.size();
			while(!st.empty())
			{
				ll tt=st.top();
				st.pop();
				parent[tt]=i;
				size[tt]=c;
				diameter[tt]=dd;
			}
		}
	}
	while(q--)
	{
		ll alarm;
		cin>>alarm;
		if(alarm==1)
		{
			ll node;
			cin>>node;
			cout<<diameter[find_set(node)]<<"\n";
		}
		else
		{
			ll a,b;
			cin>>a>>b;
			union_sets(a,b);
		}
	}
    return 0;
}


//252908XL