		/*Read the problem carefully before starting to work on it*/

//?

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

ll dp[200005][2];

void fill_dp()
{
    for(ll i=0;i<200005;i++)
    {
        for(ll j=0;j<2;j++)
        {
                dp[i][j]=(1e18+100);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,a,b;
	    cin>>n>>a>>b;
	    string s;
	    cin>>s;
	    fill_dp();
	    dp[0][0]=b;
	    for(ll i=1;i<n;i++)
	    {
	        if(s[i]=='0')
	        {
	            if(s[i-1]=='0')
	            {
	                dp[i][0]=min(dp[i][0],dp[i-1][0]+a+b);
	                dp[i][0]=min(dp[i][0],dp[i-1][1]+2ll*a+b);
	                dp[i][1]=min(dp[i][1],dp[i-1][1]+a+2ll*b);
	                dp[i][1]=min(dp[i][1],dp[i-1][0]+2ll*a+2ll*b);
	            }
	            else
	            {
	                dp[i][0]=min(dp[i][0],dp[i-1][0]+a+b);
	                dp[i][1]=min(dp[i][1],dp[i-1][1]+a+2ll*b);
	            }
	        }
	        else
	        {
	            if(s[i-1]=='0')
	            {
	                dp[i][1]=min(dp[i][1],dp[i-1][1]+a+2ll*b);
	                dp[i][1]=min(dp[i][1],dp[i-1][0]+2ll*a+2ll*b);
	            }
	            else
	            {
	                dp[i][1]=min(dp[i][1],dp[i-1][1]+2ll*b+a);
	            }
	        }
	    }
	    cout<<min(dp[n-1][0]+a+b,dp[n-1][1]+2ll*a+b)<<"\n";
	}
    return 0;
}


//252908XL