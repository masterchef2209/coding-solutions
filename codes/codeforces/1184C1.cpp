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

bool check(ll x1,ll y1,ll x2,ll y2,pair<ll,ll>&a)
{
    if(x1==a.fi && (a.se>=y1 && a.se<=y2))
        return true;
    if(x2==a.fi && (a.se>=y1 && a.se<=y2))
        return true;
    if(y1==a.se && (a.fi>=x1 && a.fi<=x2))
        return true;
    if(y2==a.se && (a.fi>=x1 && a.fi<=x2))
        return true;
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	n=4*n+1;
	vector< pair<ll,ll> >vv;
	map<ll,ll>cx,cy;
	for(ll u=0;u<n;u++)
	{
	    ll x,y;
	    cin>>x>>y;
	    vv.eb(x,y);
	    cx[x]++;
	    cy[y]++;
	}
	ll x1=INT_MAX,y1=INT_MAX,x2=INT_MIN,y2=INT_MIN;
	for(auto &x:cx)
	{
	    if(x.se>=2)
	    {
	         x1=min(x1,x.fi);
	         x2=max(x2,x.fi);
	    }
	   
	}
	for(auto &y:cy)
	{
	    if(y.se>=2)
	    {
	        y1=min(y1,y.fi);
	        y2=max(y2,y.fi);
	    }
	}
	for(auto &p:vv)
	{
	    if(!check(x1,y1,x2,y2,p))
	    {
	        cout<<p.fi<<" "<<p.se;
	        return 0;
	    }
	}
	
    return 0;
}