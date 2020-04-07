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

set<ll>bon;

void push(ll arr[],ll v)
{
	if(arr[v]!=0)
	{
		arr[v*2]=arr[v*2+1]=arr[v];
		arr[v]=0;
	}
}

void update(ll arr[],ll v,ll tl,ll tr,ll l,ll r,ll val)
{
	if(l>r)
		return;
	if(r<tl || l>tr)
		return;
	if(tl==tr)
	{
		arr[v]=val;
		return;
	}
	ll tm=(tl+tr)/2;
	push(arr,v);
	update(arr,v*2,tl,tm,l,r,val);
	update(arr,v*2+1,tm+1,tr,l,r,val);
}

void cnt(ll arr[],ll v,ll tl,ll tr)
{
	if(arr[v]!=0)
	{
		bon.insert(arr[v]);
		return;
	}
	ll tm=(tl+tr)/2;
	cnt(arr,v*2,tl,tm);
	cnt(arr,v*2+1,tm+1,tr);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		bon.clear();
		ll n;
		cin>>n;
		set<ll>ss;
		map< ll,ll >mm;
		vector< pair<ll,ll>  >qq;
		for(ll u=0;u<n;u++)
		{
			ll a,b;
			cin>>a>>b;
			qq.eb(a,b);
			ss.insert(a);
			ss.insert(b);
		}
		ll lol=0;
		for(auto &noo:ss)
		{
			mm[noo]=lol++;
		}
		ll arr[4*lol];
		ll frick=1;
		for(auto &x:qq)
		{
			ll a=mm[x.fi];
			ll b=mm[x.se];
			update(arr,1,0,lol-1,a,b,frick++);
		}
		cnt(arr,1,0,lol-1);
		cout<<(bon.size())<<"\n";
	}
    return 0;
}


//252908XL

/*
comments:-

*/
