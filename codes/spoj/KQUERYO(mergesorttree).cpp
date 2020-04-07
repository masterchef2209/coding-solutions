		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)

//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};

#define fi first
#define se second

#define SSIZE 30004
ll pre=0;
ll n;
vector<ll> t[4*SSIZE];
ll arr[4*SSIZE];

void build(ll v,ll tl,ll tr)
{
	if(tl==tr)
	{
		t[v].eb(arr[tl]);
		return;
	}
	ll tm=(tl+tr)/2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v].resize((t[v*2].size()+t[v*2+1].size()));
	merge(t[v*2].begin(),t[v*2].end(),t[v*2+1].begin(),t[v*2+1].end(),t[v].begin());
}

ll query(ll v,ll tl,ll tr,ll l,ll r,ll k)
{
	if(l>r)
		return 0;
	if(r<tl || l>tr)
		return 0;
	if(l<=tl && r>=tr)
	{
		auto it=upper_bound(t[v].begin(),t[v].end(),k);
		return (t[v].end()-it);
	}
	ll tm=(tl+tr)/2;
	ll one=query(v*2,tl,tm,l,r,k);
	ll two=query(v*2+1,tm+1,tr,l,r,k);
	return (one+two);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	build(1,0,n-1);
	ll m;
	cin>>m;
	while(m--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		a^=pre;
		b^=pre;
		c^=pre;
		a--;
		b--;
		ll ans=query(1,0,n-1,a,b,c);
		cout<<ans<<"\n";
		pre=ans;
	}
    return 0;
}


//252908XL

/*
comments:-

*/
