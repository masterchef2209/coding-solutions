		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

#define SSIZE 2005

ll n,h,l,r;

ll dp[SSIZE][SSIZE];

bool check(ll num)
{
    num%=h;
    if(num>=l && num<=r)
        return 1;
    else
        return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>h>>l>>r;
	vector<ll>arr(n+10,0);
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	vector<ll>pre(n+10,0);
	pre[1]=arr[1];
	for(ll i=2;i<=n;i++)
	{
	    pre[i]=pre[i-1]+arr[i]+h;
	}
	dp[1][0]=check(arr[1]);
	dp[1][1]=check(arr[1]-1);
	for(ll i=2;i<=n;i++)
	{
		for(ll x=0;x<=(i-1);x++)
		{
			dp[i][x]=max(dp[i][x],dp[i-1][x]+check(pre[i-1]-x+h+arr[i]));
			dp[i][x+1]=max(dp[i][x+1],dp[i-1][x]+check(pre[i-1]-x+h+arr[i]-1));
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	for(ll x=0;x<=i;x++)
	{
		ans=max(ans,dp[i][x]);
	}
	cout<<ans;
    return 0;
}


//252908XL