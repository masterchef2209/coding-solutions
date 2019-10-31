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

ll n,k;

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
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(ll i=0;i<=n;i++)
	{
		make_set(i);
	}
	ll ans=0;
	for(ll u=0;u<k;u++)
	{
		ll a,b;
		cin>>a>>b;
		if(find_set(a)==find_set(b))
		{
			ans++;
		}
		else
		{
			union_sets(a,b);
		}
	}
	cout<<ans;
    return 0;
}


//252908XL