		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream cin("input.txt")
//#define of1 ofstream cout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll s,b;
	cin>>s>>b;
	vector<ll>att(s);
	for(ll i=0;i<s;i++)
		cin>>att[i];
	vector< pair<ll,ll> >def(b);
	for(ll i=0;i<b;i++)
	{
		ll d,g;
		cin>>d>>g;
		def[i]=make_pair(d,g);
	}
	sort(def.begin(),def.end());
	for(ll i=1;i<b;i++)
	{
		def[i].se+=def[i-1].se;
	}
	for(ll i=0;i<s;i++)
	{
		ll lo=0;
		ll hi=b-1;
		while(lo<hi)
		{
			ll mid=lo+(hi-lo+1)/2;
			if(def[mid].fi<=att[i])
			{
				lo=mid;
			}
			else
			{
				hi=mid-1;
			}
		}
		if(lo==0 && att[i]<def[0].fi)
		{
		    cout<<0<<" ";
		}
		else
		    cout<<def[lo].se<<" ";
	}
    return 0;
}