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

ll dp[5005];
ll p[5005];

int main()
{
	ll n,w,h;
	scanf("%lld %lld %lld",&n,&w,&h);
	vector< pair< pair<ll,ll>,ll > >arr;
	for(ll u=0;u<n;u++)
	{
		ll wi,hi;
		scanf("%lld %lld",&wi,&hi);
		if(wi>w && hi>h)
		{
			arr.eb(mp(wi,hi),u+1);
		}
	}
	sort(arr.begin(),arr.end());
	if(arr.empty())
	{
		cout<<0;
		return 0;
	}
	dp[0]=1;
	for(ll i=0;i<arr.size();i++)
	    p[i]=-1;
	for(ll i=1;i<arr.size();i++)
	{
		for(ll j=0;j<i;j++)
		{
			if(arr[i].fi.fi>arr[j].fi.fi && arr[i].fi.se>arr[j].fi.se)
			{
			     if((dp[j]+1)>=dp[i])
			     {
			        p[i]=j;
			        dp[i]=dp[j]+1;
			     }
			}
		}
	}
    ll lol=-1;
    ll value=-1;
    for(ll i=0;i<arr.size();i++)
    {
        if(dp[i]>value)
        {
            value=dp[i];
            lol=i;
        }
    }
    stack<ll>ans;
    while(lol>=0)
    {
        ans.push(arr[lol].se);
        lol=p[lol];
    }
    cout<<ans.size()<<"\n";
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    //good one
    return 0;
}