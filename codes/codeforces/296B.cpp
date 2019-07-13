		/*Read the problem carefully before starting to work on it*/
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

//#define fi1 ifstream cin("input.txt")
//#define of1 ofstream cout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

ll dp[100005][2];
ll c=1;
ll d=1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	dp[0][0]=1;
	dp[0][1]=1;
	string s1,s2;
	cin>>s1>>s2;
	for(ll i=1;i<=n;i++)
	{
		ll j=i-1;
		if(s1[j]=='?' && s2[j]=='?')
		{
			dp[i][0]=(55*(dp[i-1][0]%mod))%mod;
			dp[i][1]=(55*(dp[i-1][1]%mod))%mod;
			c*=10;
			c%=mod;
			d*=10;
			d%=mod;
			d*=10;
			d%=mod;
		}
		else if(s1[j]=='?')
		{
			dp[i][0]=(((s2[j]-'0')+1)%mod*dp[i-1][0]%mod)%mod;
			dp[i][1]=((9-(s2[j]-'0')+1)%mod*dp[i-1][1]%mod)%mod;
			d*=10;
			d%=mod;
		}
		else if(s2[j]=='?')
		{
			dp[i][0]=( (9-(s1[j]-'0')+1)%mod*dp[i-1][0]%mod)%mod;
			dp[i][1]=(((s1[j]-'0')+1)%mod*dp[i-1][1]%mod)%mod;
			d*=10;
			d%=mod;
		}
		else
		{
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][1];
			if(s1[j]>s2[j])
			{
			    c=0;
			    dp[i][0]=c;
			}
			else if(s2[j]>s1[j])
			{
			    c=0;
			    dp[i][1]=c;
			}
		}
	}
	ll e=((dp[n][0]+dp[n][1])%mod-c+mod+mod)%mod;
	cout<<(d-e+mod)%mod;
    return 0;
}