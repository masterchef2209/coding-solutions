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

ll n,m;
ll dp[SSIZE];

vector< pair<ll,ll> >lights;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	dp[m]=0;
	for(ll u=0;u<n;u++)
	{
		ll pos,s;
		cin>>pos>>s;
		lights.eb(max(0LL,pos-s),min(m,pos+s));
	}
	lights.eb(0,0);
	for(ll i=m-1;i>=0;i--)
	{
		ll lol=(m-i);
		for(auto &x:lights)
		{
		    if((i+1)>=x.fi && (i+1)<=x.se)
		    {
		        lol=dp[i+1];
		        break;
		    }
			if(i<(x.fi))
			{
				lol=min(lol,x.fi-i-1+dp[min(m,x.se+x.fi-i-1)]);
			}
		}
		dp[i]=lol;
	}
	cout<<dp[0];
    return 0;
}


//252908XL