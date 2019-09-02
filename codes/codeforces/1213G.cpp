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
#define SSIZE 200005

ll n,m;
ll ans;
set< pair<ll,pair<ll,ll> > >edges;
vector<pair<ll,ll> >qq;

ll parent[SSIZE];
ll size[SSIZE];

void make_set(ll i)
{
	parent[i]=i;
	size[i]=1;
}

ll find_set(ll i)
{
	if(i==parent[i])
		return i;
	return parent[i]=find_set(parent[i]);
}

inline ll nC2(ll x)
{
	return (x*(x-1))/2;
}

void union_sets(ll a,ll b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		ans+= (nC2(size[a]+size[b])-nC2(size[a])-nC2(size[b]) );
		if(size[a]<size[b])
			swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}

ll pp[SSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll u=0;u<(n-1);u++)
	{
		ll a,b,x;
		cin>>a>>b>>x;
		edges.insert(mp(x,mp(a,b)));
	}
	for(ll u=0;u<m;u++)
	{
		ll q;
		cin>>q;
		qq.eb(mp(q,u) );
	}
	sort(qq.begin(),qq.end());
	for(ll i=0;i<=n;i++)
	{
		make_set(i);
	}
	ans=0;
	ll pos=0;
	for(auto &x:edges)
	{
		ll weight=x.fi;
		ll a=x.se.fi;
		ll b=x.se.se;
		if(weight<=qq[pos].fi)
		{
			union_sets(a,b);
		}
		else
		{
			while(pos<m && weight>qq[pos].fi)
			{
				//cout<<ans<<" ";
				pp[qq[pos].se]=ans;
				pos++;
			}
			union_sets(a,b);
		}
	}
	while(pos<m)
	{
		//cout<<ans<<" ";
		pp[qq[pos].se]=ans;
		pos++;
	}
	for(ll u=0;u<m;u++)
	{
	    cout<<pp[u]<<" ";
	}
    return 0;
}


//252908XL