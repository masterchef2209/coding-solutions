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

#define SIZE 100005

ll arr[SIZE];
ll dp[SIZE][2][2];

ll n;

void initialize()
{
    for(ll i=1;i<=n;i++)
    {
        dp[i][0][0]=INT_MIN;
        dp[i][0][1]=INT_MIN;
        dp[i][1][0]=INT_MIN;
        dp[i][1][1]=INT_MIN;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	initialize();
	for(ll i=1;i<=n;i++)
	{
		dp[i][0][0]=max(dp[i][0][0],dp[i-1][1][0]+arr[i]);
		dp[i][0][0]=max(dp[i][0][0],dp[i-1][0][0]+arr[i]);

		dp[i][1][0]=max(dp[i][1][0],dp[i-1][1][0]-arr[i]);

		dp[i][0][1]=max(dp[i][0][1],dp[i-1][0][0]-arr[i]);
		dp[i][0][1]=max(dp[i][0][1],dp[i-1][0][1]-arr[i]);
		dp[i][0][1]=max(dp[i][0][1],dp[i-1][1][0]-arr[i]);
		dp[i][0][1]=max(dp[i][0][1],dp[i-1][1][1]-arr[i]);

		dp[i][1][1]=max(dp[i][1][1],dp[i-1][1][0]+arr[i]);
		dp[i][1][1]=max(dp[i][1][1],dp[i-1][1][1]+arr[i]);
	}
	ll ans=INT_MIN;
	for(ll i=0;i<2;i++)
		for(ll j=0;j<2;j++)
		{
			ans=max(ans,dp[n][i][j]);
		}
	cout<<ans;
    return 0;
}


//252908XL