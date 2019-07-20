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
 
double grid[18][18];
double dp[(1LL<<18)][18];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(ll mask=1;mask<(1LL<<n);mask++)
	{
		ll tt=__builtin_popcount(mask);
		    // if fish is alone it will surely survive (base case)
		    for(ll i=0;i<n;i++)
		    {
		        if(mask&(1LL<<i) && tt==1)
		            dp[mask][i]=1;
		        else
		            dp[mask][i]=0;
		    }
		ll cnt=tt*(tt-1)/2;
		if(cnt==0)
		    continue;
		for(ll i=0;i<n;i++)
		{
		    if(mask&(1LL<<i))
		    {
		        for(ll j=i+1;j<n;j++)
		        {
		            if(mask&(1LL<<j))
		            {
		                for(ll k=0;k<n;k++)
		                {
		                    dp[mask][k]+=(grid[i][j]*dp[mask^(1LL<<j)][k]/cnt);
		                    dp[mask][k]+=(grid[j][i]*dp[mask^(1LL<<i)][k]/cnt);
		                }
		            }
		        }
		    }
		}
	}
	cout<<fixed<<setprecision(8);
	for(ll i=0;i<n;i++)
	{
		cout<<(dp[(1LL<<n)-1][i])<<" ";
	}
    return 0;
}