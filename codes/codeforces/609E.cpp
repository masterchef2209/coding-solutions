	/*Read the problem carefully before starting to work on it*/
	//why me so stupid lol
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
#define int long long
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
 
const int MAX = 2e5 + 5;
long long size[MAX];
int arr[MAX];
pair< long long, pair<int,int> > p[MAX],p1[MAX];
vector< pair<ll,ll> > adj[MAX];
int n,m;
void initialize()
{
  for(int i=0;i<MAX;i++)
  {
    arr[i]=i;
    size[i]=1;
  }
}
 
int root(int i)
{
  while(i!=arr[i])
  {
    arr[i]=arr[arr[i]];
    i=arr[i];
  }
return i;
}
 
void dsu(int a,int b)
{
  int rootA=root(a);
  int rootB=root(b);
  if(size[rootA]<size[rootB])
  {
    arr[rootA]=arr[rootB];
    size[rootB]+=size[rootA];
  }
  else
  {
    arr[rootB]=arr[rootA];
    size[rootA]+=size[rootB];
  }
}
 
long long kruskal()
{
  long long minCost=0;
  for(int i=0;i<m;i++)
  {
    int a=p[i].second.first;
    int b=p[i].second.second;
    long long cost=p[i].first;
    if(root(a)!=root(b))
    {
      adj[a].eb(b,cost);
	  adj[b].eb(a,cost);    
      dsu(a,b);
      minCost+=cost;
    }
  }
return minCost;
}
 
const ll BSIZE=23;
ll dp[MAX][BSIZE];
ll mx[MAX][BSIZE];
ll level[MAX];
 
void dfs(ll curr,ll par)
{
	for(auto &nei:adj[curr])
	{
		if(nei.fi==par)
			continue;
		dp[nei.fi][0]=curr;
		mx[nei.fi][0]=nei.se;
		level[nei.fi]=level[curr]+1;
		dfs(nei.fi,curr);
	}
}
 
ll LCA(ll a,ll b)
{
	ll ret=0;
	if(level[a]<level[b])
		swap(a,b);
	ll diff=level[a]-level[b];
	for(ll i=BSIZE-1;i>=0;i--)
	{
		if((diff>>i)&1)
		{
			ret=max(ret,mx[a][i]);
			a=dp[a][i];
		}
	}
	if(a==b)
		return ret;
	for(ll i=BSIZE-1;i>=0;i--)
	{
		if(dp[a][i] && dp[a][i]!=dp[b][i])
		{
			ret=max(ret,mx[a][i]);
			ret=max(ret,mx[b][i]);
			a=dp[a][i];
			b=dp[b][i];
		}
	}
	ret=max(ret,mx[a][0]);
	ret=max(ret,mx[b][0]);
	return ret;
}
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initialize();
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		p[i]=mp(w,mp(a,b));
		p1[i]=mp(w,mp(a,b));
	}
	sort(p,p+m);
	ll mstcost=kruskal();
	dfs(1,0);
	for(ll i=1;i<BSIZE;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			dp[j][i]=dp[dp[j][i-1]][i-1];
			mx[j][i]=max(mx[j][i-1],mx[dp[j][i-1]][i-1]);
		}
	}
	for(ll i=0;i<m;i++)
	{
		ll a=p1[i].se.fi;
		ll b=p1[i].se.se;
		ll w=p1[i].fi;
		ll val=LCA(a,b);
	//	cout<<val<<endl;
		cout<< mstcost+w-val<<endl;
	}
    return 0;
}
 
 
//252908XL
 
/*
comments:-
Nice problem 5/5
Learned the implemmentation of LCA. Nice problem in which heaviest edge between 2 nodes in a tree is
maintained with the LCA. This problem also uses minimum spanning tree cost calculation.
Tarjan's Criterion:-
If there exists an edge (x,y) which does not belong to the MST of the tree then the heaviest edge on the path from 
x to y through the MST will still have lesser weight than the edge (x,y).
So, in other words for this problem if we add edge (x,y) a cycle is formed and we already had a path from x to y, now we have
added direct edge from x to y, so we can get rid of previous path. To break the previous path such that the MSt have least weight, it is
optimal to remove heaviest edge on this path.
*/