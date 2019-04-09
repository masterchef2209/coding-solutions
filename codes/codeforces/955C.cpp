#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
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
typedef unsigned long long ll;
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
const ll lim=1e18;
set<ll>ss;
vector<ll>vv;

ll sqt(ll x) {
  ll lo = 0, hi = 1e9;
  while (lo < hi) {
    ll m =( lo + hi + 1 )>> 1;
    if (1LL*m*m > x)
      hi = m - 1;
    else
      lo = m;
  }
  return lo;
}

ll checksq(ll k)
{
	ll root=sqt(k);
	for(ll i=root-1;i<=root+1;i++)
	{
		if(i*i==k)
			return 1;
	}
	return 0;
}

void process()
{
	for(ll i=2;i<=1e6;i++)
	{
		ll cur=i*i*i;
		while(true)
		{
			if(!checksq(cur))
				ss.insert(cur);
			if(cur<=lim/i)
				cur*=i;
			else
				break;
		}
	}
	for(auto it:ss)
		vv.push_back(it);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	process();
	ll q;
	cin>>q;
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		auto st=lower_bound(vv.begin(),vv.end(),l);
		auto en=upper_bound(vv.begin(),vv.end(),r);
		cout<<((sqt(r))-(sqt(l-1)) )+distance(st,en)<<endl;
	}
    return 0;
}