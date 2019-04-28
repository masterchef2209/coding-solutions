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

#define int long long

vector<ll>factors;

void computefactors(ll num)
{
	for(ll i=1;i*i<=num;i++)
	{
	    if(num%i==0)
	    {
	        factors.eb(i);
	        if((num/i)!=i)
	        {
	            factors.eb(num/i);
	        }
	    }
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b;
	cin>>a>>b;
	if(a==b)
	{
	    cout<<0<<endl;
	    return 0;
	}
	if(b<a)
		swap(a,b);
	computefactors(b-a);
	ll templcm=LLONG_MAX,ans=LLONG_MAX;
	for(auto &d:factors)
	{
		ll k;
		if(a%d==0)
			k=0;
		else
			k=d-(a%d);
		ll temp=((a+k)*(b+k))/d;
		if(temp<templcm)
		{
			templcm=temp;
		    ans=k;
		}
		else if(temp==templcm)
		{
		    ans=min(ans,k);
		}
	}
	cout<<ans;
    return 0;
}