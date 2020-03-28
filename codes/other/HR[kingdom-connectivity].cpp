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
#define mod 1000000000

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

ll n,m;

#define SSIZE 100005

vector< vector<ll> >adj(SSIZE),adj1(SSIZE);
vector<ll>lol;
vector<ll>vis(SSIZE,0);
ll dist[SSIZE];
ll mark[SSIZE];

bool findLoop(int v) 
{
	if(vis[v]==1)
	{
	    mark[v]=1;
		return 1;
	}
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	for(auto &it:adj1[v])
	{
		if(findLoop(it))
			return 1;
	}
	vis[v]=2;
	return 0;
}

ll fl=0;

void dfs(ll curr)
{
	vis[curr]=1;
	if(mark[curr])
	    fl=1;
	for(auto &nei:adj[curr])
	{
		if(!vis[nei])
			dfs(nei);
	}
	lol.eb(curr);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj1[b].eb(a);
	}
	findLoop(n);
	for(ll i=0;i<=n;i++)
	{
		vis[i]=0;
	}
	dfs(1);
	if(fl)
	{
		cout<<"INFINITE PATHS";
		return 0;
	}
	reverse(lol.begin(),lol.end());
	dist[lol[0]]=1;
	for(ll i=0;i<n;i++)
	{
		for(auto &nei:adj[lol[i]])
		{
			dist[nei]+=dist[lol[i]];
			dist[nei]%=mod;
		}
	}
	cout<<dist[n];
    return 0;
}


//252908XL