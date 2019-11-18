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

#define SSIZE 2010

string s;

ll palindrome[SSIZE][SSIZE];
ll dp[SSIZE];
ll sum[SSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	for(ll i=0;i<s.size();i++)
		palindrome[i][i]=1;
	for(ll i=0;i<(s.size()-1);i++)
	{
		if(s[i]==s[i+1])
			palindrome[i][i+1]=1;
		else
			palindrome[i][i+1]=0;
	}
	for(ll L=3;L<=s.size();L++)
	{
		for(ll st=0,en=st+L-1;en<s.size();st++,en++)
		{
			palindrome[st][en]=(palindrome[st+1][en-1]&&(s[st]==s[en]));
		}
	}
	dp[0]=0;
	sum[0]=1;
	for(ll i=1;i<s.size();i++)
	{
	    ll tem1=0;
		for(ll j=1;j<=i;j++)
		{
			tem1+=(palindrome[j][i]*sum[j-1]);
		}
		dp[i]=dp[i-1]+tem1;
		ll tem=0;
		for(ll j=0;j<=i;j++)
			tem+=palindrome[j][i];
		sum[i]=sum[i-1]+tem;
	}
	cout<<dp[s.size()-1];
    return 0;
}


//252908XL