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

ll arr[110][110];
ll dp[110][110];

vector<ll>ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			char tmp;
			cin>>tmp;
			arr[i][j]=(tmp-'0');
			if(arr[i][j]==1)
				dp[i][j]=1;
			else
				dp[i][j]=(1<<29);
			if(i==j)
			    dp[i][j]=0;
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
	ll m;
	cin>>m;
	vector<ll>arr(m);
	for(ll i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	ans.eb(arr[0]);
	ll prev=0;
	for(ll i=1;i<m;i++)
	{
		if(dp[arr[prev]][arr[i]]<(i-prev))
		{
		    ans.eb(arr[i-1]);
			prev=i-1;
		}
	}
	ans.eb(arr[m-1]);
	cout<<ans.size()<<"\n";
	for(auto &x:ans)
	{
	    cout<<x<<" ";
	}
    return 0;
}


//252908XL