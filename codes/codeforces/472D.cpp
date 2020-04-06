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
#define SSIZE 2005

ll n;
ll arr[SSIZE][SSIZE];

const int N=2005;
const int LG=log2(N)+1;

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
			{
				parent[i][j]=parent[i-1][parent[i-1][j]];
				mx[i][j]=mx[i-1][j]+mx[i-1][parent[i-1][j]];
			}
}

int LCA(int u, int v)
{
	int ret=0;
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			ret+=mx[i][u];
			u=parent[i][u];
		}
	}
	if(u==v)
		return ret;
	for(int i=LG-1;i>=0;i--)
	{
		if(parent[i][u] && parent[i][u]!=parent[i][v])
		{
			ret+=mx[i][u];
			ret+=mx[i][v];
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	ret+=mx[0][u];
	ret+=mx[0][v];
	return ret;
}

int dist(int u, int v)
{
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}

const int MAX = N;
long long size[MAX];
int arr1[MAX];
pair< long long, pair<int,int> > p[N*N];
void initialize()
{
  for(int i=0;i<MAX;i++)
  {
    arr1[i]=i;
    size[i]=1;
  }
}

int root(int i)
{
  while(i!=arr1[i])
  {
    arr1[i]=arr1[arr1[i]];
    i=arr1[i];
  }
return i;
}

void dsu(int a,int b)
{
  int rootA=root(a);
  int rootB=root(b);
  if(size[rootA]<size[rootB])
  {
    arr1[rootA]=arr1[rootB];
    size[rootB]+=size[rootA];
  }
  else
  {
    arr1[rootB]=arr1[rootA];
    size[rootA]+=size[rootB];
  }
}
ll lul=0;
long long kruskal()
{
  long long minCost=0;
  for(int i=0;i<lul;i++)
  {
    int a=p[i].second.first;
    int b=p[i].second.second;
    long long cost=p[i].first;
    if(root(a)!=root(b))
    {
      dsu(a,b);
      g[a].eb(b,cost);
      g[b].eb(a,cost);
      minCost+=cost;
    }
  }
return minCost;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	bool ok=true;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i==j)
			{
				if(arr[i][j]!=0)
				{
					ok=false;
				}
			}
			else
			{
				if(arr[i][j]==0)
				{
					ok=false;
				}
				if(arr[i][j]!=arr[j][i])
				{
					ok=false;
				}
			}
		}
	}
	if(!ok)
	{
		cout<<"NO";
		return 0;
	}
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            p[lul++]=mp(arr[i][j],mp(i+1,j+1));
        }
    }
    sort(p,p+lul);
    initialize();
    kruskal();
	dfs(1,0,1);
	precompute();
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			if(LCA(i+1,j+1)!=arr[i][j])
			{
				ok=false;
			}
		}
	}
	if(!ok)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
    return 0;
}


//252908XL

/*
comments:-
Very nice problem, after doing trivial checks we notice that we notice that in minimal tree if we add additional edges with weights equal to shortest path distance we get what is exacly given in problem.
Hence if we take the MST of this graph we get our tree back. MST can be constructed and distance between any 2 nodes of the MST is maintained in LCA by binary lifting, after this distance from matrix and from
the tree can be compared to check for inconsistencies. One thing to notice that if we don't take distances in ascending order we will get a larger weight edge then which must be present in the tree and thus wrong answer,
Or if we take it in ascending order and combine unlesss we have not seen both nodes before. This is very similar to what kruskal does but here we will get a forest in which all trees are subtrees of required trees. Hence building
a MST is the way to go. This implementation builds the MST using kruskal.
Also solution to e-olymp 7413.
*/
