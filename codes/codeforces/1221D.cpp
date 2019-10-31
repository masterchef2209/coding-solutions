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

#define INF 1e16

#define SSIZE 300005

ll dp[SSIZE][3];
ll a[SSIZE];
ll b[SSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q;
	cin>>q;
	while(q--)
	{
	    ll n;
	    cin>>n;
	    a[0]=-10;
	    b[0]=0;
	    for(ll i=1;i<=n;i++)
	    {
	        cin>>a[i]>>b[i];
	    }
	    for(ll i=0;i<=n;i++)
	    for(ll j=0;j<3;j++)
	    {
	        dp[i][j]=INF;
	    }
	    dp[0][0]=0;
	    for(ll i=1;i<=n;i++)
	    {
	        for(ll j=0;j<3;j++)
	        {
	            for(ll k=0;k<3;k++)
	            {
	                if((a[i]+j)!=(a[i-1]+k))
	                {
	                    dp[i][j]=min(dp[i][j],b[i]*j+dp[i-1][k]);
	                }
	            }
	        }
	    }
	    ll ans=INF;
	    for(ll i=0;i<3;i++)
	    {
	        ans=min(ans,dp[n][i]);
	    }
	    cout<<ans<<"\n";
	}
    return 0;
}


//252908XL