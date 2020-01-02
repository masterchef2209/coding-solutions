		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

#define SSIZE 3005

ll dp[SSIZE][SSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	string s;
	cin>>s;
	dp[1][1]=1;
	for(ll len=2;len<=n;len++)
	{
		for(ll i=1;i<=(len-1);i++)
		{
			dp[len-1][i]+=dp[len-1][i-1];
			dp[len-1][i]%=mod;
		}
		for(ll b=1;b<=len;b++)
		{
			ll L,R;
			if(s[len-2]=='<')
			{
				L=1;
				R=b-1;
			}
			else
			{
				L=b;
				R=len-1;
			}
			if(L<=R)
			{
				dp[len][b]+=( (dp[len-1][R]-dp[len-1][L-1]+mod)%mod );
				dp[len][b]%=mod;
			}
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ans+=dp[n][i];
		ans%=mod;
	}
	cout<<ans;
    return 0;
}


//252908XL