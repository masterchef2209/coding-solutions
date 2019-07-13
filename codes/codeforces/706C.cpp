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

#define INF 1e15

ll dp[100005][2];

string pp[100005][2];

bool check(ll index,ll sta1,ll sta2)
{
	string one=pp[index-1][sta2];
	string two=pp[index][sta1];
	for(ll i=0;i<min(one.size(),two.size());i++)
	{
		if(one[i]<two[i])
			return true;
		if(two[i]<one[i])
			return false;
	}
	if(one.size()<=two.size())
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>cost(n);
	for(ll i=0;i<n;i++)
		cin>>cost[i];
	for(ll i=0;i<n;i++)
	{
		string x;
		cin>>x;
		string y=x;
		reverse(y.begin(),y.end());
		pp[i][0]=x;
		pp[i][1]=y;
	}
	dp[0][0]=0;
	dp[0][1]=cost[0];
	for(ll i=1;i<n;i++)
	{
		for(ll j=0;j<2;j++)
		{
			dp[i][j]=INF;
			if(check(i,j,j))
				dp[i][j]=min(dp[i][j],dp[i-1][j]+j*cost[i]);
			if(check(i,j,j^1))
				dp[i][j]=min(dp[i][j],dp[i-1][j^1]+j*cost[i]);
		}
	}
	ll ans=min(dp[n-1][0],dp[n-1][1]);
	if(ans==INF)
		cout<<-1;
	else
		cout<<ans;
    return 0;
}