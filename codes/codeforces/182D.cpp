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

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

std::set<string> get_divisors(string s)
{
	set<string> ret;
	ll len=s.size();
	vector<ll>factors;
	for(ll i=1;i*i<=len;i++)
	{
		if(len%i==0)
			factors.eb(i);
		if(i!=(len/i))
			factors.eb(len/i);
	}
	for(auto &x:factors)
	{
		string temp=s.substr(0,x);
		ll y=len/x;
		string temp1("");
		while(y--)
			temp1+=temp;
		if(temp1==s)
			ret.insert(temp);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1,s2;
	cin>>s1>>s2;
	set<string>div1,div2,ans;
	div1=get_divisors(s1);
	div2=get_divisors(s2);
	set_intersection(div1.begin(),div1.end(),div2.begin(),div2.end(),inserter(ans,ans.begin()));
	cout<<ans.size();
    return 0;
}