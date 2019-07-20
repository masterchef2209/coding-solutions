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

ll nCr[1005][1005];

void precompute() 
{ 
  	for(int i=0;i<=1001;i++)
  	{
  		for(int j=0;j<=1001;j++)
  		{
  			nCr[i][j]=0;
  		}
  	}
   	for(int i=0;i<=1001;i++)
   	{
   		nCr[i][0]=1;
   	}
  	for(int i=1;i<=1001;i++)
  	{
  		for(int j=1;j<=i;j++)
  		{
  			nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%mod;
  		}
  	}
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	ll k;
	cin>>k;
	vector<ll>c(k+1);
	vector<ll>dp(k+1);
	for(ll i=1;i<=k;i++)
	{
		cin>>c[i];
	}
	dp[0]=1;
	c[0]=0;
	ll cc=0;
	for(ll i=1;i<=k;i++)
	{
		dp[i]=((dp[i-1]%mod)*(nCr[cc+c[i]-1][c[i]-1])%mod)%mod;
		cc+=c[i];
	}
	cout<<dp[k];
    return 0;
}