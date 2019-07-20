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

ll n,m;
ll bp;
ll dp[11][(1LL<<11)];

vector< pair<ll,ll> >points(21);

ll f(ll at,ll mask)
{
	if(dp[at][mask]!=-1)
		return dp[at][mask];
	if(mask==( (1LL<<(bp+1) ) -1))
	{
		return dp[at][mask]=(abs(points[at].fi-points[0].fi)+abs(points[at].se-points[0].se));
	}
	ll temp=LLONG_MAX;
	for(ll i=0;i<=bp;i++)
	{
		if((mask&(1LL<<i))==0)
		{
			ll lel=f(i,mask|(1LL<<i))+(abs(points[at].fi-points[i].fi)+abs(points[at].se-points[i].se));
			temp=min(temp,lel);
		}
	}
	return dp[at][mask]=temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cin>>points[0].fi>>points[0].se;
		cin>>bp;
		for(ll i=1;i<=bp;i++)
		{
			cin>>points[i].fi>>points[i].se;
		}
		memset(dp,-1,sizeof(dp));
		cout<<"The shortest path has length "<<f(0,1)<<"\n";
	}
    return 0;
}