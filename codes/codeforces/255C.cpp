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

#define SIZE 1005

char grid[SIZE][SIZE];

ll dp[2][SIZE];

ll wcount[SIZE];
ll bcount[SIZE];

ll n,m,x,y;

void fill_dp()
{
	for(ll i=0;i<2;i++)
	for(ll j=0;j<=m;j++)
		dp[i][j]=INT_MAX;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m>>x>>y;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>grid[i][j];
			
		}
	}
	for(ll j=1;j<=m;j++)
	{
		ll wc=0,bc=0;
		for(ll i=1;i<=n;i++)
		{
			if(grid[i][j]=='.')
			{
				wc++;
			}
			else
			{
				bc++;
			}
		}
		wcount[j]=wcount[j-1]+wc;
		bcount[j]=bcount[j-1]+bc;
	}
	fill_dp();
	dp[0][0]=0;
	dp[1][0]=0;
	for(ll j=1;j<=m;j++)
	{
		for(ll k=x;k<=y;k++)
		{
			if(j-k>=0)
			{
				dp[0][j]=min(dp[0][j],dp[1][j-k]+bcount[j]-bcount[j-k]);
				dp[1][j]=min(dp[1][j],dp[0][j-k]+wcount[j]-wcount[j-k]);
			}
		}
	}
	cout<<min(dp[0][m],dp[1][m]);
    return 0;
}


//252908XL