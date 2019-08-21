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

#define SIZE 1010

bool ch[SIZE][SIZE];
ll dp[SIZE];

vector< vector<ll> >arr(6,vector<ll>(SIZE));

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<k;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(ll i=0;i<k;i++)
	{
		for(ll pos1=0;pos1<n-1;pos1++)
		{
			for(ll pos2=pos1+1;pos2<n;pos2++)
			{
				ch[arr[i][pos2]][arr[i][pos1]]=true;
			}
		}
	}
	for(ll i=0;i<n;i++)
	{
		dp[i]=1;
		for(ll j=0;j<i;j++)
		{
			if(ch[arr[0][j]][arr[0][i]]==false)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	// dp[i] is longest length of LCS such that element at position i in 1st array is last element in LCS
	ll ans=1;
	for(ll i=0;i<n;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
    return 0;
}


//252908XL