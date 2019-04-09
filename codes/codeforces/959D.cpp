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

vl factors[2000005];
ll hh[2000005]={0};
ll hh1[2000005]={0};
set<ll>s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=2;i<2000005;i++)
	{
		if(!hh[i])
		{
			for(ll j=i;j<2000005;j+=i)
			{
				factors[j].eb(i);
				hh[j]=1;
			}
		}
		s.insert(i);
	}
	ll flag=1;
	for(ll u=0;u<n;u++)
	{
		ll temp;
		cin>>temp;
		ll out= *s.begin();
		if(flag)
		{
			out= *s.lower_bound(temp);
			if(out!=temp)
				flag=0;
		}
		cout<<out<<" ";
		for(auto &no:factors[out])
		{
			for(ll o=no;o<2000005;o+=no)
			{
				if(!hh1[o])
				{
					s.erase(o);
					hh1[o]=1;
				}
			}
		}
	}
    return 0;
}