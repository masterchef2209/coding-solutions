/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
typedef int ll;
 
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
 
#define N 1000016
const int LG=log2(N)+1;
 
int n,q;
int tim=0;
int parent[LG][N];
int tin[N], tout[N], level[N];
vector<int> g[N];
 
void dfs(int k, int par, int lvl)
{
	tin[k]=++tim;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	tout[k]=tim;
}
 
int walk(int u, int h)
{
	for(int i=LG-1;i>=0;i--)
	{
		if((h>>i) & 1)
			u = parent[i][u];
	}
	return u;
}
 
void precompute()
{
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
}
 
int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			u=parent[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--)
	{
		if(parent[i][u] && parent[i][u]!=parent[i][v])
		{
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}
 
int dist(int u, int v)
{
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}
 
ll qq[N];
ll dia=2;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	n=4;
	cin>>q;
	g[1].eb(2);
	g[1].eb(3);
	g[1].eb(4);
	for(ll i=0;i<q;i++)
	{
		cin>>qq[i];
		g[qq[i]].eb(n+1);
		g[qq[i]].eb(n+2);
		qq[i]=n+1;
		n+=2;
	}
	dfs(1,0,1);
	precompute();
	ll v1=2;
	ll v2=4;
	for(ll i=0;i<q;i++)
	{
	    //cout<<v1<<" "<<v2<<endl;
		ll d1=dist(qq[i],v1);
		ll d2=dist(qq[i],v2);
		if(d1>dia)
		{
			dia=d1;
			v2=qq[i];
		}
		if(d2>dia)
		{
			dia=d2;
			v1=qq[i];
		}
		cout<<dia<<endl;
	}
    return 0;
}
 
 
//252908XL
 
/*
comments:-
one of the niceset LCA problem i have seen till now, the problem involves maintaining the dynamic diameter of a tree 
as it is build, the solution just involves moving 2 pointers greedily which denote the end points of a diameter. The diameter length is denoted by
distance formula between 2 nodes of a tree which involves use of LCA.
*/
