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

int main()
{
	int x,y,z,k;
	scanf("%d %d %d %d",&x,&y,&z,&k);
	vector<ll>xx,yy,zz,ans;
	for(int i=0;i<x;i++)
	{
		ll tmp;
		scanf("%lld",&tmp);
		xx.eb(tmp);
	}
	for(int i=0;i<y;i++)
	{
		ll tmp;
		scanf("%lld",&tmp);
		yy.eb(tmp);
	}
	for(int i=0;i<z;i++)
	{
		ll tmp;
		scanf("%lld",&tmp);
		zz.eb(tmp);
	}
	sort(xx.rbegin(),xx.rend());
	sort(yy.rbegin(),yy.rend());
	sort(zz.rbegin(),zz.rend());
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			for(int m=0;m<z;m++)
			{
				if( ((i+1)*(j+1)*(m+1))>k )
					break;
				ans.eb(xx[i]+yy[j]+zz[m]);
			}
		}
	}
    sort(ans.rbegin(),ans.rend());
    int index=0;
	while(index<ans.size() && k>0)
	{
		printf("%lld\n",ans[index]);
		k--;
		index++;
	}
    return 0;
}
