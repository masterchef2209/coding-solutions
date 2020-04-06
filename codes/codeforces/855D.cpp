/*Read the problem carefully before starting to work on it*/
//why me so stupid TT
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
const int LG=31;
int n,q;
 
int tim=0;
int parent[LG][N];
int mx[LG][N];
int tin[N], tout[N], level[N];
vector< pair<int,int> > g[N];
 
void dfs(int k, int par, int lvl)
{
	tin[k]=++tim;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it.fi==par)
			continue;
		mx[0][it.fi]=it.se;
		dfs(it.fi, k, lvl+1);
	}
	tout[k]=tim;
}
 
int walk(int u, int h)
{
	ll sum=0;
	for(int i=LG-1;i>=0;i--)
	{
		if((h>>i) & 1)
		{
			sum+=mx[i][u];
			u = parent[i][u];
		}
	}
	if(sum!=0)
		return -1;
	return u;
}
 
int walk1(int u, int h)
{
	int h1=h;
	ll sum=0;
	for(int i=LG-1;i>=0;i--)
	{
		if((h>>i) & 1)
		{
			sum+=mx[i][u];
			u = parent[i][u];
		}
	}
	if(sum!=h1)
		return -1;
	return u;
}
 
void precompute()
{
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
		{
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
			mx[i][j]=mx[i-1][j]+mx[i-1][parent[i-1][j]];
		}
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
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<int>roots;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a==-1)
		{
		    roots.eb(i);
			continue;
		}
		g[a].eb(i,b);
		g[i].eb(a,b);
	}
	for(auto &x:roots)
        dfs(x,0,1);
	precompute();
	cin>>q;
	while(q--)
	{
		int st;
		cin>>st;
		int u,v;
		cin>>u>>v;
		if(st==1)
		{
			int diff=level[v]-level[u];
			if(diff<=0)
			{
				cout<<"NO\n";
				continue;
			}
			int nn=walk(v,diff);
			if(nn!=u)
			{
				cout<<"NO\n";
			}
			else
			{
				cout<<"YES\n";
			}
		}
		else
		{
		    if(u==v)
		    {
		        cout<<"NO\n";
		        continue;
		    }
			int w=LCA(u,v);
			if(w==v)
			{
			    cout<<"NO\n";
			    continue;
			}
			int diff1=level[u]-level[w];
			int nn1=walk(u,diff1);
			if(nn1!=w)
			{
				cout<<"NO\n";
				continue;
			}
			int diff2=level[v]-level[w];
			int nn2=walk1(v,diff2);
			if(nn2!=w)
			{
				cout<<"NO\n";
				continue;
			}
			cout<<"YES\n";
		}
	}
    return 0;
}
 
 
//252908XL
 
/*
comments:-
2400, more like 800 lol
easy LCA, easy observation
*/