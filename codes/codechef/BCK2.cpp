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
#define int long long
#define N 100005

int nodes=0;
int subtree[N], parentcentroid[N];
set<int> g[N];

vector< vector< pair<ll,ll> > >adj(N);

void dfs(int k, int par)
{
	nodes++;
	subtree[k]=1;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		subtree[k]+=subtree[it];
	}
}

int centroid(int k, int par)
{
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		if(subtree[it]>(nodes>>1))
			return centroid(it, k);
	}
	return k;
}

ll ans=0;

void dfs1(ll curr,ll par,ll dist)
{
    ans+=(2*dist);
    for(auto &nei:adj[curr])
    {
        if(nei.fi==par)
            continue;
        dfs1(nei.fi,curr,dist+nei.se);
    }
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<(n-1);i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		g[a].insert(b);
		g[b].insert(a);
		adj[a].eb(mp(b,w));
		adj[b].eb(mp(a,w));
	}
	dfs(1,1);
	int node=centroid(1,1);
	//cout<<node<<endl;
	dfs1(node,-1,0);
	cout<<ans<<endl;
    return 0;
}


//252908XL