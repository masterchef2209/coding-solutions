		/*Read the problem carefully before starting to work on it*/

//300 IQ solution idea by Illuminati97

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
	vector< pair<ll,ll> >arr(n);
	for(ll i=0;i<n;i++)
	{
		ll tmp;
		cin>>tmp;
		arr[i]=mp(tmp,i+1);
	}
	if(n==2)
	{
	    cout<<1;
	    return 0;
	}
	sort(arr.begin(),arr.end());
	map<ll,ll>mm;
	for(ll i=1;i<n;i++)
	{
		mm[arr[i].fi-arr[i-1].fi]++;
	}
	for(ll i=0;i<n;i++)
	{
		if(i==0)
		{
			mm[arr[i+1].fi-arr[i].fi]--;
			if(mm[arr[i+1].fi-arr[i].fi]==0)
				mm.erase(arr[i+1].fi-arr[i].fi);
			if(mm.size()==1)
			{
				cout<<arr[i].se;
				return 0;
			}
			mm[arr[i+1].fi-arr[i].fi]++;
		}
		else if(i==n-1)
		{
			mm[arr[i].fi-arr[i-1].fi]--;
			if(mm[arr[i].fi-arr[i-1].fi]==0)
				mm.erase(arr[i].fi-arr[i-1].fi);
			if(mm.size()==1)
			{
				cout<<arr[i].se;
				return 0;
			}
			mm[arr[i].fi-arr[i-1].fi]++;
		}
		else
		{
			mm[arr[i].fi-arr[i-1].fi]--;
			if(mm[arr[i].fi-arr[i-1].fi]==0)
				mm.erase(arr[i].fi-arr[i-1].fi);
			mm[arr[i+1].fi-arr[i].fi]--;
			if(mm[arr[i+1].fi-arr[i].fi]==0)
				mm.erase(arr[i+1].fi-arr[i].fi);
			mm[arr[i+1].fi-arr[i-1].fi]++;
			if(mm.size()==1)
			{
				cout<<arr[i].se;
				return 0;
			}
			mm[arr[i].fi-arr[i-1].fi]++;
			mm[arr[i+1].fi-arr[i].fi]++;
			mm[arr[i+1].fi-arr[i-1].fi]--;
			if(mm[arr[i+1].fi-arr[i-1].fi]==0)
				mm.erase(arr[i+1].fi-arr[i-1].fi);
		}
	}
	cout<<-1;
    return 0;
}