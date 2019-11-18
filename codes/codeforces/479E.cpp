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

#define SSIZE 5005

ll N,A,B,K;

ll dp[SSIZE][SSIZE];

void fill_dp()
{
    for(ll i=0;i<SSIZE;i++)
    for(ll j=0;j<SSIZE;j++)
        dp[i][j]=0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill_dp();
	cin>>N>>A>>B>>K;
	dp[0][A]=1;
	for(ll k=1;k<=K;k++)
	{
		for(ll i=1;i<=N;i++)
		{
			dp[k-1][i]+=dp[k-1][i-1];
			dp[k-1][i]%=mod;
		}
		for(ll i=1;i<=N;i++)
		{
			if(i==B)
				continue;
			ll val=0;
			ll mid=0;
			if(i<B)
			{
				mid=(i+B)/2;
				if((B-mid)==(mid-i))
				    mid--;
				val=(dp[k-1][mid]-dp[k-1][0]+mod)%mod;
			}
			else
			{
				mid=(i+B)/2;
				val=(dp[k-1][N]-dp[k-1][mid]+mod)%mod;
			}
			
			//cout<<i<<" "<<mid<<"\n";
			
			ll lol=(dp[k-1][i]-dp[k-1][i-1]+mod)%mod;
			
			val=(val-lol+mod)%mod;
			dp[k][i]=val;
		}
	}
	
	//debug
// 	for(ll i=1;i<=N;i++)
// 	{
// 	    cout<<dp[1][i]<<" ";
// 	}
	
	ll ans=0;
	if(A<B)
	for(ll flr=1;flr<B;flr++)
	{
		ans+=dp[K][flr];
		ans%=mod;
	}
	else
	for(ll flr=B+1;flr<=N;flr++)
	{
		ans+=dp[K][flr];
		ans%=mod;
	}
	//cout<<"\n";
	cout<<ans;
    return 0;
}


//252908XL