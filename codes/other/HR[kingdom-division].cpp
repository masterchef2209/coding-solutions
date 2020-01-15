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

#define SSIZE 100005

ll n;

vector< vector<ll> >adj(SSIZE);

ll dp[SSIZE][2][2];
// states- root of subtree, color of root , if the color is same as parent
// 0 denotes red, 1 denotes blue

void fill_dp()
{
    for(ll i=0;i<SSIZE;i++)
    for(ll j=0;j<2;j++)
    for(ll k=0;k<2;k++)
    {
        dp[i][j][k]=-1;
    }
}

ll f(ll root,ll color,ll same,ll prev)
{
    if(dp[root][color][same]!=-1)
        return dp[root][color][same];
	if(adj[root].size()==1 && prev!=-1)
	{
		if(same==0)
		{
			return dp[root][color][same]=0;
		}
		else
		{
			return dp[root][color][same]=1;
		}
	}
	ll val1=1;
	ll val2=1;
	for(auto &nei:adj[root])
	{
		if(nei==prev)
			continue;
		val1*=(f(nei,color,1,root)%mod + f(nei,color^1,0,root)%mod)%mod;
		val1%=mod;
		val2*=(f(nei,color^1,0,root))%mod;
		val2%=mod;
	}
	if(same==0)
	{
		ll val3=(val1-val2+mod)%mod;
		return dp[root][color][same]=val3;
	}
	else
	{
		return dp[root][color][same]=val1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill_dp();
	cin>>n;
	for(ll u=0;u<(n-1);u++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	cout<< ( f(1,0,0,-1)+f(1,1,0,-1) )%mod<<"\n";
    return 0;
}


//252908XL