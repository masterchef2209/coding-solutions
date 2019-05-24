//read announcement for this problem

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

#define int long long

#define fi first
#define se second

ll dp1[1005][1005]={0};
ll dp2[1005][1005]={0};
ll dp3[1005][1005]={0};
ll dp4[1005][1005]={0};

ll grid[1005][1005];

void precompute(ll n, ll m)
{
	for(ll i=1;i<=n;i++)
	{
		dp1[i][1]=dp1[i-1][1]+grid[i][1];
	}
	for(ll i=1;i<=m;i++)
	{
		dp1[1][i]=dp1[1][i-1]+grid[1][i];
	}
	for(ll i=2;i<=n;i++)
	{
		for(ll j=2;j<=m;j++)
		{
			dp1[i][j]=grid[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
		}
	}
	for(ll i=n;i>=1;i--)
	{
		dp2[i][1]=dp2[i+1][1]+grid[i][1];
	}
	for(ll i=1;i<=m;i++)
	{
		dp2[n][i]=dp2[n][i-1]+grid[n][i];
	}
	for(ll i=n-1;i>=1;i--)
	{
		for(ll j=2;j<=m;j++)
		{
			dp2[i][j]=grid[i][j]+max(dp2[i+1][j],dp2[i][j-1]);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		dp3[i][m]=dp3[i-1][m]+grid[i][m];
	}
	for(ll i=m;i>=1;i--)
	{
		dp3[1][i]=dp3[1][i+1]+grid[1][i];
	}
	for(ll i=2;i<=n;i++)
	{
		for(ll j=m-1;j>=1;j--)
		{
			dp3[i][j]=grid[i][j]+max(dp3[i-1][j],dp3[i][j+1]);
		}
	}
	for(ll i=n;i>=1;i--)
	{
		dp4[i][m]=dp4[i+1][m]+grid[i][m];
	}
	for(ll i=m;i>=1;i--)
	{
		dp4[n][i]=dp4[n][i+1]+grid[n][i];
	}
	for(ll i=n-1;i>=1;i--)
	{
		for(ll j=m-1;j>=1;j--)
		{
			dp4[i][j]=grid[i][j]+max(dp4[i+1][j],dp4[i][j+1]);
		}
	}
}

ll solve(ll i,ll j)
{
	ll ret=max(dp1[i][j-1]+dp2[i+1][j]+dp3[i-1][j]+dp4[i][j+1],dp1[i-1][j]+dp2[i][j-1]+dp3[i][j+1]+dp4[i+1][j]);
	return ret;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>grid[i][j];
		}
	}
	
	precompute(n,m);

	ll ans=-1;
	// 1<rx<n 1<ry<m otherwise paths will intersect and it will violate the condition given in announcement
	for(ll rx=2;rx<n;rx++)
	{
		for(ll ry=2;ry<m;ry++)
		{
		    ll tmp=solve(rx,ry);
		 
			ans=max(ans,tmp);
		}
	}
	cout<<ans;
    return 0;
}