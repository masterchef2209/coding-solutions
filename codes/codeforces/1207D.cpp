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
#define mod 998244353

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

ll n;
vector< pair<ll,ll> >pp(300005);

ll fac[300005];

void initialize()
{
	fac[0]=1;
	for(ll i=1;i<300005;i++)
	{
		fac[i]=(fac[i-1]%mod * i%mod)%mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initialize();
	cin>>n;
	map<ll,ll>m1,m2;
	map<ll,vector<ll> >lis;
	for(ll i=0;i<n;i++)
	{
		cin>>pp[i].fi>>pp[i].se;
		m1[pp[i].fi]++;
		m2[pp[i].se]++;
	}
	ll ans=0;
	ll tem1=1,tem2=1;
	for(auto &x:m1)
	{
		tem1=(tem1%mod * fac[x.se]%mod)%mod;
	}
	for(auto &x:m2)
	{
		tem2=(tem2%mod * fac[x.se]%mod)%mod;
	}
	ans+=tem1;
	ans%=mod;
	ans+=tem2;
	ans%=mod;
	sort(pp.begin(),pp.begin()+n);
	int flag=0;
	map< pair<ll,ll>,ll>cry;
	cry[pp[0]]++;
	for(ll i=1;i<n;i++)
	{
		if(pp[i].se<pp[i-1].se)
		{
			flag=1;
			break;
		}
		cry[pp[i]]++;
	}
	if(flag==1)
	{
		cout<<(fac[n]-ans+mod)%mod;
		return 0;
	}
	ll val=1;
	for(auto &x:cry)
	{
		val=(val%mod * fac[x.se]%mod)%mod;
	}
	ans=(ans+mod-(val%mod) )%mod;
	cout<<(fac[n]-ans+mod)%mod;
    return 0;
}

//252908XL