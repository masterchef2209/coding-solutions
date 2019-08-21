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

ll dp[510][510];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(ll len=1;len<=n;len++)
	{
		for(ll beg=0,en=len-1;en<n;beg++,en++)
		{
			if(len==1)
			{
				dp[beg][en]=1;
			}
			else
			{
				dp[beg][en]=1+dp[beg+1][en];
				if(arr[beg]==arr[beg+1])
				{
					dp[beg][en]=min(dp[beg+2][en]+1,dp[beg][en]);
				}
				for(ll k=beg+2;k<=en;k++)
				{
					if(arr[beg]==arr[k])
						dp[beg][en]=min(dp[beg+1][k-1]+dp[k+1][en],dp[beg][en]);
				}

			}
		}
	}
	cout<<dp[0][n-1];
    return 0;
}


//252908XL