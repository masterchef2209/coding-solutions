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

ll dp[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
	    if(s[i]=='m' || s[i]=='w')
	    {
	        cout<<0;
	        return 0;
	    }
	}
	ll n=s.size();
	if(n==1)
	{
	    cout<<1;
	    return 0;
	}
	dp[0]=1;
	if((s[0]=='n' && s[1]=='n') || (s[0]=='u' && s[1]=='u'))
	    dp[1]=2;
	else
	    dp[1]=1;
	for(ll i=2;i<n;i++)
	{
	    if(s[i]=='u')
	    {
	        if(s[i-1]=='u')
	        {
	            dp[i]=(dp[i-1]%mod + dp[i-2]%mod)%mod;
	        }
	        else
	        {
	            dp[i]=dp[i-1];
	        }
	    }
	    else if(s[i]=='n')
	    {
	        if(s[i-1]=='n')
	        {
	            dp[i]=(dp[i-1]%mod + dp[i-2]%mod)%mod;
	        }
	        else
	        {
	            dp[i]=dp[i-1];
	        }
	    }
	    else
	    {
	        dp[i]=dp[i-1];
	    }
	}
	cout<<dp[n-1];
    return 0;
}


//252908XL