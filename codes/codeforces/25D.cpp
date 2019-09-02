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
#define SSIZE 1005
 
ll n;
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
 
vector< pair<ll,ll> >ans,ans1;
map<ll,vector<ll> >mm;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll u=0;u<=n;u++)
	    make_set(u);
	for(ll u=0;u<(n-1);u++)
	{
		ll a,b;
		cin>>a>>b;
		ll rootA=find_set(a);
		ll rootB=find_set(b);
		if(rootA!=rootB)
		{
			union_sets(a,b);
		}
		else
		{
			ans.eb(a,b);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		parent[i]=find_set(i);
	}
	for(ll i=1;i<=n;i++)
	{
		mm[parent[i]].eb(i);
	}
	ll prev=-1;
	for(auto it=mm.begin();it!=mm.end();it++)
	{
		ll tem=*((it->se).begin());
		if(it!=mm.begin())
		{
			ans1.eb(prev,tem);
		}
		prev=tem;
	}
	cout<<ans.size()<<"\n";
	for(ll i=0;i<ans.size();i++)
	{
		cout<<ans[i].fi<<" "<<ans[i].se<<" "<<ans1[i].fi<<" "<<ans1[i].se<<"\n";
	}
    return 0;
}
 
 
//252908XL