/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
 
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
 
double PI=3.1415926535897932384626;
 
//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
 
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)
 
//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};
 
#define fi first
#define se second
 
#define SSIZE 200005
ll n,k;
 
vector< vector<ll> >adj(SSIZE);
ll hh[SSIZE];
ll mark[SSIZE];
ll ssize[SSIZE];
 
void dfs(ll curr,ll par,ll val)
{
	hh[curr]=val;
	ssize[curr]=1;
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		dfs(nei,curr,val+1);
		ssize[curr]+=ssize[nei];
	}
	hh[curr]-=ssize[curr];
}
 
ll ans=0;
 
void dfs1(ll curr,ll par,ll val)
{
	if(mark[curr]==0)
		val++;
	else
	{
		ans+=val;
	}
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		dfs1(nei,curr,val);
	}
}
 
priority_queue< pair<ll,ll> >pq; 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(ll u=0;u<(n-1);u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	dfs(1,-1,0);
 
	for(ll i=1;i<=n;i++)
	{
		pq.push(mp(hh[i],i));
	}
	while(k--)
	{
		auto pp=pq.top();
		pq.pop();
		mark[pp.se]=1;
	}
	dfs1(1,-1,0);
	cout<<ans;
    return 0;
}
 
 
//252908XL
 
/*
comments:-
 
*/