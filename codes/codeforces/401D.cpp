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

ll dp[(1LL<<19)][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string num;
	ll m;
	cin>>num>>m;
	ll n=num.size();
	ll grid[n][n];
	ll count0=0;
	for(ll i=0;i<num.size();i++)
	{
		if(num[i]=='0')
			count0++;
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i<1)
			{
				if(num[j]=='0')
				{
					grid[i][j]=0;
				}
				else
				{
					grid[i][j]=1;
				}
			}
			else
			{
				grid[i][j]=1;
			}
		}
	}
	dp[0][0]=1;
	for(ll mask=1;mask<(1LL<<n);mask++)
	{
		ll tem=__builtin_popcount(mask)-1;
		set<char>bag;
		for(ll j=0;j<n;j++)
		{
			if(mask&(1LL<<j) && grid[tem][j]==1 && bag.find(num[j])==bag.end() )
			{
			    bag.insert(num[j]);
				for(ll momo=0;momo<m;momo++)
				{
					dp[mask][(momo*10+(num[j]-'0'))%m]+=dp[mask^(1LL<<j)][momo];
				}
			}
		}
	}
	cout<<dp[(1LL<<n)-1][0];
    return 0;
}