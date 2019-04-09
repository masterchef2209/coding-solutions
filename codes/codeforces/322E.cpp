#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
//using namespace __gnu_pbds;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

char ans[100005];
set<int>adj[100005];
int nodes;
int subtree[100005];

void dfs(int curr,int parent)
{
	nodes++;
	subtree[curr]=1;
	for(auto &nei:adj[curr])
	{
		if(nei==parent)
			continue;
		dfs(nei,curr);
		subtree[curr]+=subtree[nei];
	}
}

int centroid(int curr,int parent)
{
	for(auto &nei:adj[curr])
	{
		if(nei==parent)
			continue;
		if(subtree[nei]>(nodes>>1))
			return centroid(nei,curr);
	}
	return curr;
}

void decompose(int curr,char rank)
{
	nodes=0;
	dfs(curr,curr);
	int cent=centroid(curr,curr);
	ans[cent]=rank;
	for(auto &nei:adj[cent])
	{
		adj[nei].erase(cent);
		decompose(nei,rank+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	decompose(1,'A');
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}