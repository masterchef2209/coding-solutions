#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//not accepted
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

vector<ll>arr(100005);
ll n,s;

ll dp[1005][1005];

ll f(ll l,ll r,map<ll,ll>&mm)
{
	if(dp[l][r]!=-1)
		return dp[l][r];
	if((l>r))
	{
		ll count=0;
		for(auto &x:mm)
		{
			if(x.se<=s)
			{
				count+=x.se;
			}
		}
		return dp[l][r]=max(dp[l][r],count);
	}
	if(((mm[arr[l]]<=s) &&  (mm[arr[r]]<=s))|| )
	{
		return dp[l][r]=max(dp[l][r],max(f(l+1,r,mm),f(l,r-1,mm)));
	}
	else if((mm[arr[l]]>s) &&  (mm[arr[r]]>s))
	{
		map<ll,ll>m1=mm,m2=mm;
		m1[arr[l]]--;
		m2[arr[r]]--;
		return dp[l][r]=max(dp[l][r],max(f(l+1,r,m1),f(l,r-1,m2)));
	}
	else
	{
		if((mm[arr[l]]>s))
		{
			map<ll,ll>m1=mm;
			m1[arr[l]]--;
			return dp[l][r]=max(dp[l][r],f(l+1,r,m1));
		}
		else if((mm[arr[r]]>s))
		{
			map<ll,ll>m2=mm;
			m2[arr[r]]--;
			return dp[l][r]=max(dp[l][r],f(l,r-1,m2));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	for(ll u=1;u<=t;u++)
	{
		cout<<"Case #"<<u<<": ";
		cin>>n>>s;
		for(ll i=0;i<=n;i++)
		{
			for(ll j=0;j<=n;j++)
			{
				dp[i][j]=-1;
			}
		}
		map<ll,ll>mm;
		for(ll i=1;i<=n;i++)
		{
			cin>>arr[i];
			mm[arr[i]]++;
		}
		ll l=1,r=n;
		cout<<f(l,r,mm)<<"\n";
	}
    return 0;
}