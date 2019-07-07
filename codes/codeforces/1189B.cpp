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
	ll n;
	cin>>n;
    vector<ll>e,o,arr,arr1;
    for(ll i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        arr1.eb(tmp);
    }
    sort(arr1.begin(),arr1.end());
    for(ll i=0;i<n;i++)
    {
        if(i&1)
            o.eb(arr1[i]);
        else
            e.eb(arr1[i]);
    }
    sort(o.begin(),o.end());
    sort(e.rbegin(),e.rend());
    for(auto &x:o)
    {
        arr.eb(x);
    }
    for(auto &x:e)
    {
        arr.eb(x);
    }
	if((arr[0]>=(arr[1]+arr[n-1])))
	{
		cout<<"NO\n";
		return 0;
	}
	for(ll i=1;i<n;i++)
	{
		if(arr[i]>=(arr[i-1]+arr[(i+1)%n]))
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(ll i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
    return 0;
}