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

ll n,k;

vector<ll>arr(200005);
vector<ll>ans(200005);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	set< pair<ll,ll> >ss;
	set<ll>nodes;
	for(int u=0;u<n;u++)
	{
		ll value;
		cin>>value;
		arr[u+1]=value;
		ss.insert(mp(-value,u+1));
		nodes.insert(u+1);
	}
	
	ll turn=0;
	while(!nodes.empty())
	{
	    ll curr=ss.begin()->se;
		ans[curr]=turn+1;
		nodes.erase(curr);
		ss.erase(ss.begin());
		for(int times=0;times<k;times++)
		{
			auto big=nodes.lower_bound(curr+1);
			if(big==nodes.end())
				break;
			ans[*big]=turn+1;
			ss.erase(mp(-arr[*big],*big));
			nodes.erase(*big);
		}
		for(int times=0;times<k;times++)
		{
			auto small=nodes.upper_bound(curr-1);
			if(small==nodes.begin())
				break;
			ans[*prev(small)]=turn+1;
			ss.erase(mp(-arr[*prev(small)],*prev(small) ));
			nodes.erase(*prev(small));
		}
		turn^=1;
	}
	for(int x=1;x<=n;x++)
	{
		cout<<ans[x];
	}
    return 0;
}