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
#define SSIZE 100005

ll n,m;

vector< pair<ll,ll> >threads;
vector< ll >deletion;
vector<ll>flag(SSIZE,0);

vector<ll>ans;

ll parent[SSIZE];
ll size[SSIZE];

ll pppupu;

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

void union_sets(ll a,ll b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		pppupu--;
		if(size[a]<size[b])
			swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	pppupu=n;
	for(ll i=0;i<=n;i++)
	{
		make_set(i);
	}
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		threads.eb(a,b);
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll id;
		cin>>id;
		id--;
		deletion.eb(id);
		flag[id]=1;
	}
	ll naw=0;
	for(auto &x:threads)
	{
		if(flag[naw++]==1)
		{}
		else
		{
			union_sets(x.fi,x.se);
		}
	}
	reverse(deletion.begin(),deletion.end());
	for(auto &x:deletion)
	{
	    pair<ll,ll>xx=threads[x];
		ans.eb( pppupu );
		union_sets(xx.fi,xx.se);
	}
	reverse(ans.begin(),ans.end());
	for(auto &x:ans)
	{
		cout<<x<<" ";
	}
    return 0;
}


//252908XL