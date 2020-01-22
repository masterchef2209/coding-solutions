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
#define mod 1000000007LL

double PI=3.1415926535897932384626;

template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	string s;
	cin>>s;
	char x,y;
	cin>>x>>y;
	if(x==y)
	{
		ll ans=0;
		ll temp=0;
		ll fl=0;
		ll cc=0;
		for(ll i=n-1;i>=0;i--)
		{
			if(s[i]==x && fl==1)
			{
				ll inv=power(2LL,mod-2);
				ll temp1=power(inv,i+1);
				ans+=( (temp%mod * temp1%mod)%mod );
				ans%=mod;
			}
			if(s[i]==y)
			{
				temp+=power(2LL,i);
				temp%=mod;
				cc++;
				cc%=mod;
				fl=1;
			}
		}
		cout<<(ans%mod + cc%mod)%mod;
	}
	else
	{
		ll ans=0;
		ll temp=0;
		for(ll i=n-1;i>=0;i--)
		{
			if(s[i]==y)
			{
				temp+=power(2LL,i);
				temp%=mod;
			}
			if(s[i]==x)
			{
				ll inv=power(2LL,mod-2);
				ll temp1=power(inv,i+1);
				ans+=( (temp%mod * temp1%mod)%mod );
				ans%=mod;
			}
		}
		cout<<ans;
	}
    return 0;
}


//252908XL