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

#define SIZE 200005

vector<ll>arr(SIZE);
vector<ll>perm(SIZE);
vector<ll>parent(SIZE,-1);
vector<ll>sum(SIZE);
vector<ll>sz(SIZE);

ll find_set(ll v)
{
	if(parent[v]==-1)
		return v;
	return parent[v]=find_set(parent[v]);
}


void union_sets(ll a,ll b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		if(sz[b]>sz[a])
			swap(a,b);
		sz[a]+=sz[b];
		sum[a]+=sum[b];
		parent[b]=a;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	
	for(ll i=0;i<n;i++)
	{
		cin>>perm[i];
		perm[i]--;
	}
	reverse(perm.begin(),perm.begin()+n);
	ll cur=0;
	stack<ll>ans;
	for(ll i=0;i<n;i++)
	{
		ans.push(cur);
		ll a=perm[i];
		sz[a]=1;
	    sum[a]=arr[a];
		if(a>0 && sz[a-1]>0)
		{
			union_sets(a-1,a);
		}
		if(a<(n-1) && sz[a+1]>0)
		{
			union_sets(a,a+1);
		}
		cur=max(cur,sum[find_set(a)]);
	}
	while(!ans.empty())
	{
		cout<<ans.top()<<"\n";
		ans.pop();
	}
    return 0;
}


//252908XL