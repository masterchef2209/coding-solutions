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

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

bool flag[1000005];

#define S 1000000

int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=S;i++)
		flag[i]=false;
	vector<ll>ans;
	ll cnt=0;
	for(ll u=0;u<n;u++)
	{
	    ll tmp;
	    scanf("%lld",&tmp);
	    flag[tmp]=true;
	}
	for(ll x=1;x<=S;x++)
	{
		if(flag[x]==false)
			continue;
		ll y=S-x+1;
		if(flag[y])
		{
			cnt++;
		}
		else
		{
			ans.eb(y);
		}
	}
	for(ll i=1;i<=S;i++)
	{
	    if(cnt>0 && flag[i]==false && flag[S-i+1]==false)
	    {
	        flag[i]=true;
	        flag[S-i+1]=true;
	        ans.eb(i);
	        ans.eb(S-i+1);
	        cnt-=2;
	    }
	    if(cnt<=0)
	        break;
	}
	cout<<ans.size()<<"\n";
	for(auto &x:ans)
	{
	    cout<<x<<" ";
	}
    return 0;
}