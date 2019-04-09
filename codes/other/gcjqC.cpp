#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
//using namespace __gnu_pbds;
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
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second
#define int long long

signed main()
{
	int t;
	cin>>t;
	for(int u=1;u<=t;u++)
	{
	    printf("Case #%lld: ",u);
		set<int> ss;
		int n,l;
		scanf("%lld %lld",&n,&l);
		vector<int>code;
		vector<int>ans;
		for(int i=0;i<l;i++)
		{
			int tmp;
			scanf("%lld",&tmp);
			code.eb(tmp);
		}
		ll h=__gcd(code[0],code[1]);
		ss.insert(h);
		ss.insert(code[0]/h);
		ans.eb(code[0]/h);
		ans.eb(h);
		for(int i=2;i<l-1;i++)
		{
			ss.insert(__gcd(code[i-1],code[i]));
			ans.eb(__gcd(code[i-1],code[i]));
		}
		int w=__gcd(code[l-2],code[l-1]);
		ss.insert(w);
		ss.insert(code[l-1]/w);
		ans.eb(w);
		ans.eb(code[l-1]/w);
		for(int i=0;i<ans.size();i++)
		{
			printf("%c",(char)(distance(ss.begin(),ss.find(ans[i]))+'A'));
		}
		printf("\n");
	}
    return 0;
}