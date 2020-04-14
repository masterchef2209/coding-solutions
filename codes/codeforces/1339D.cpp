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

#define SSIZE 100005

ll n;
vector< vector<ll> >adj(SSIZE);
vector<ll>leaves;
set<ll>leaf,fuck;
ll visited[SSIZE];

ll fl=0;

void dfs(ll curr,ll val)
{
	visited[curr]=1;
	if(leaf.find(curr)!=leaf.end())
	{
		if(val&1)
		{
			fl=1;
		}
	}
	for(auto &nei:adj[curr])
	{
		if(visited[nei])
			continue;
		dfs(nei,val+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll  i=0;i<(n-1);i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	for(ll i=1;i<=n;i++)
	{
		if(adj[i].size()==1)
		{
			leaves.eb(i);
			leaf.insert(i);
		}
	}
	ll mans=n-1;
	ll hehe=0;
	for(auto &x:leaves)
	{
		ll nei=adj[x][0];
		ll lul=0;
		for(auto &y:adj[nei])
		{
			if(leaf.find(y)!=leaf.end())
			{
				lul++;
			}
			if(lul>=2)
			    break;
		}
		if(lul>=2)
		{
			fuck.insert(nei);
			hehe++;
		}
	}
	mans-=hehe;
	mans+=(fuck.size());
	dfs(leaves[0],0);
	ll mians=1;
	if(fl)
		mians=3;
	cout<<mians<<" "<<mans;
    return 0;
}


//252908XL

/*
comments:-

*/
