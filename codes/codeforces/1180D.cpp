		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef int ll;
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

#define endl "\n"

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll one1=1,one2=1,two1=n,two2=m,dir1=0,dir2=1;
	ll fill=0;
	while(fill<=(n*m))
	{
		if(fill==(n*m))
		    break;
		cout<<one1<<" "<<one2<<endl;
		fill++;
		if(fill==(n*m))
		    break;
		cout<<two1<<" "<<two2<<endl;
		fill++;
		if(fill==(n*m))
		    break;
		if(one1==n && dir1==0)
		{
			one2++;
			dir1=1;
		}
		else if(one1==1 && dir1==1)
		{
			one2++;
			dir1=0;
		}
		else
		{
			if(dir1==0)
			{
				one1++;
			}
			else
			{
				one1--;
			}
		}
		if(two1==n && dir2==0)
		{
			two2--;
			dir2=1;
		}
		else if(two1==1 && dir2==1)
		{
			two2--;
			dir2=0;
		}
		else
		{
			if(dir2==0)
			{
				two1++;
			}
			else
			{
				two1--;
			}
		}
	}
    return 0;
}