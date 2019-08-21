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

#define SIZE 101

ll dp[SIZE][SIZE][SIZE];

ll color[SIZE];

ll p[SIZE][SIZE];

ll n,m,k;

#define BIG_MAX ll(1e18)

void fill_dp()
{
	for(ll i=0;i<=n;i++)
	for(ll j=0;j<=m;j++)
	for(ll k1=0;k1<=k;k1++)
		dp[i][j][k1]=BIG_MAX;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		cin>>color[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>p[i][j];
		}
	}
	fill_dp();
	if(color[1]==0)
	{
		for(ll col=1;col<=m;col++)
		{
			dp[1][col][1]=p[1][col];
		}
	}
	else
	{
		dp[1][color[1]][1]=0;
	}
	for(ll i=2;i<=n;i++)
	for(ll k1=1;k1<=k;k1++)
	{
		if(color[i]==0)
		{
			for(ll c1=1;c1<=m;c1++)
			{
				for(ll c2=1;c2<=m;c2++)
				{
					if(c1==c2)
					{
						dp[i][c1][k1]=min(dp[i][c1][k1],dp[i-1][c2][k1]+p[i][c1]);
					}
					else
					{
						dp[i][c1][k1]=min(dp[i][c1][k1],dp[i-1][c2][k1-1]+p[i][c1]);
					}
				}
			}
		}
		else
		{
			for(ll c2=1;c2<=m;c2++)
			{
				if(color[i]==c2)
				{
					dp[i][color[i]][k1]=min(dp[i][color[i]][k1],dp[i-1][c2][k1]);
				}
				else
				{
					dp[i][color[i]][k1]=min(dp[i][color[i]][k1],dp[i-1][c2][k1-1]);
				}
			}
		}
	}
	ll ans=BIG_MAX;
	for(ll i=1;i<=m;i++)
	    ans=min(ans,dp[n][i][k]);
	if(ans>=BIG_MAX)
	    cout<<-1;
	else
	    cout<<ans;
    return 0;
}


//252908XL