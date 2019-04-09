#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
//using namespace __gnu_pbds;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
typedef long long ll;
#define mod 1000000007
double PI=3.1415926535897932384626;
template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cpp_int n,q;
	cpp_int x=2;
	cin>>n>>q;
	cpp_int edges=(2*(power(x,n,mod)-1))%mod,l=n+1,r=n+1,u=1,d=power(x,n);
	while(q--)
	{
		ll tmp;
		cin>>tmp;
		if(tmp==2)
		{
			cout<< (edges%mod) <<endl;
		}
		else if(tmp==1)
		{
			ll tmp1;
			cin>>tmp1;
			if(tmp1==1)
			{
				edges=((edges*2)%mod+r)%mod;
				u=(2*u);
				d=(2*d);
				r=l;
			}
			else if(tmp1==2)
			{
				edges=((edges*2)%mod+l)%mod;
				u=(2*u);
				d=(2*d);
				l=r;
			}
			else if(tmp1==3)
			{
				edges=((edges*2)%mod+u)%mod;
				r=(2*r);
				l=(2*l);
				u=d;
			}
			else if(tmp1==4)
			{
				edges=((edges*2)%mod+d)%mod;
				r=(2*r);
				l=(2*l);
				d=u;
			}
		}
	}
    return 0;
}