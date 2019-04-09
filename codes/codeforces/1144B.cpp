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

bool getParity(ll n) 
{ 
    bool parity = 0; 
    while (n) 
    { 
        parity = !parity; 
        n  = n & (n - 1); 
    }      
    return parity; 
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	deque<ll>odd,even;
	for(ll i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		if(temp&1)
			odd.pb(temp);
		else	even.pb(temp);
	}
	sort(odd.begin(),odd.end());
	sort(even.begin(),even.end());
	ll odsize=odd.size();
	ll evsize=even.size();
	if(abs(odd.size()-even.size())<=1)
	{
		cout<<0<<endl;
	}
	else if(odd.size()>even.size())
	{
		ll delta=odd.size()-even.size()-1;
		ll sum=0;
		for(ll i=0;i<delta;i++)
		{
			sum+=odd[i];
		}
		cout<<sum<<endl;
	}
	else
	{
		ll delta=even.size()-odd.size()-1;
		ll sum=0;
		for(ll i=0;i<delta;i++)
		{
			sum+=even[i];
		}
		cout<<sum<<endl;
	}
    return 0;
}