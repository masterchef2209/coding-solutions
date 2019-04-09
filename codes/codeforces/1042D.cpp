#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
using namespace __gnu_pbds;
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
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
typedef tree< pair<ll,ll>,null_type,less< pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

#define N 200005

ost osfirst;
ll n;
ll t;
ll arr[N],pref[N]={0};
ll ans=0;

ll getless(ost &os,ll R,ll index)
{
	return os.order_of_key({R,index});
}
ll idx=1;
int main()
{
	scanf("%lld %lld",&n,&t);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
		pref[i]=pref[i-1]+arr[i];
	}
	osfirst.insert({0,0});
	for(ll i=1;i<=n;i++)
	{
		ans+=osfirst.size()-getless(osfirst,pref[i]-t,1e9);
		osfirst.insert({pref[i],++idx});
	}
	printf("%lld",ans);
    return 0;
}