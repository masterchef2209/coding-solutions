#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

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

#define int long long

vector<int>value(300005);
vector< vector<int> >adj(300005);
vector<int>noo(300005);


void dfs(int i)
{
	if(adj[i].empty())
	{
		noo[i]=1;
		return;
	}
	if(value[i]==1)
	{
		noo[i]=LLONG_MAX;
	}
	else
	{
		noo[i]=0;
	}
	for(auto &x:adj[i])
	{
		dfs(x);
		if(value[i]==1)
		{
			noo[i]=min(noo[i],noo[x]);
		}
		else
		{
			noo[i]+=noo[x];
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>value[i];
	}
	for(int i=2;i<=n;i++)
	{
		int p;
		cin>>p;
		adj[p].eb(i);
	}
	int k=0;
	for(int i=1;i<=n;i++)
	{
	    if(adj[i].empty())
	        k++;
	}
	dfs(1);
	cout<<k-noo[1]+1;
    return 0;
}