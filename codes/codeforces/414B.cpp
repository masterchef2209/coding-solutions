//smh i am dumb

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

ll dp[2005][2005];
vector< vector<ll> >factors(2005);

void findfactors(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				factors[i].eb(j);
				if(j!=(i/j))
				{
					factors[i].eb(i/j);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=k;j++)
			dp[i][j]=0;
	}
	findfactors(n);
	for(ll i=1;i<=n;i++)
	{
		dp[i][1]=1;
	}
	for(ll i=1;i<=k;i++)
	{
		dp[1][i]=1;
	}
	for(ll len=2;len<=k;len++)
	{
		for(ll limit=2;limit<=n;limit++)
		{
			ll sum=0;
			for(auto &fac:factors[limit])
			{
				sum=((sum)%mod+(dp[fac][len-1])%mod )%mod;
			}
			dp[limit][len]=(sum)%mod;
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
	    ans=((ans)%mod+(dp[i][k])%mod )%mod;
	}
	cout<<ans;
    return 0;
}