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

ll dp[100005]={0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	for(auto &x:arr)
	{
		if(x==1)
			continue;
		else
		{
		    ll tmp=-1;
		    vector<ll>factors;
			for(ll i=1;i*i<=x;i++)
			{
				if(x%i==0)
				{
				    factors.eb(i);
					tmp=max(tmp,dp[i]);
					if(i!=(x/i))
					{
					    factors.eb(x/i);
						tmp=max(tmp,dp[x/i]);
					}
				}
			}	
			dp[x]=tmp+1;
			for(auto &y:factors)
			{
			    if(y!=1)
			        dp[y]=dp[x];
			}
		}
	}
	dp[1]=1;
	ll ans=-1;
	for(auto &x:arr)
	{
		ans=max(ans,dp[x]);
	}
	cout<<ans;
    return 0;
}