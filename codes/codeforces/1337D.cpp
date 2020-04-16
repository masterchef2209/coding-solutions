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

ll calc(ll a,ll b,ll c)
{
    ll d1=abs(a-b);
    ll d2=abs(b-c);
    ll d3=abs(c-a);
    return d1*d1+d2*d2+d3*d3;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll na,nb,nc;
		cin>>na>>nb>>nc;
		set<ll>a,b,c,ma,mb,mc;
		for(ll i=0;i<na;i++)
		{
			ll tmp;
			cin>>tmp;
			a.insert(tmp);
			ma.insert(-tmp);
		}
		for(ll i=0;i<nb;i++)
		{
			ll tmp;
			cin>>tmp;
			b.insert(tmp);
			mb.insert(-tmp);
		}
		for(ll i=0;i<nc;i++)
		{
			ll tmp;
			cin>>tmp;
			c.insert(tmp);
			mc.insert(-tmp);
		}
		ll ans=LLONG_MAX;
	    for(auto &aa:a)
	    {
	        auto itb1=b.lower_bound(aa);
	        auto itb2=mb.lower_bound(-aa);
	        auto itc1=c.lower_bound(aa);
	        auto itc2=mc.lower_bound(-aa);
	        if(itb1!=b.end() && itc2!=mc.end())
	        {
	            ans=min(ans,calc(aa,abs(*itb1),abs(*itc2)));
	        }
	        if(itc1!=c.end() && itb2!=mb.end())
	        {
	            ans=min(ans,calc(aa,abs(*itc1),abs(*itb2)));
	        }
	    }
	    for(auto &aa:b)
	    {
	        auto itb1=a.lower_bound(aa);
	        auto itb2=ma.lower_bound(-aa);
	        auto itc1=c.lower_bound(aa);
	        auto itc2=mc.lower_bound(-aa);
	        if(itb1!=a.end() && itc2!=mc.end())
	        {
	            ans=min(ans,calc(aa,abs(*itb1),abs(*itc2)));
	        }
	        if(itc1!=c.end() && itb2!=ma.end())
	        {
	            ans=min(ans,calc(aa,abs(*itc1),abs(*itb2)));
	        }
	    }
	   for(auto &aa:c)
	    {
	        auto itb1=b.lower_bound(aa);
	        auto itb2=mb.lower_bound(-aa);
	        auto itc1=a.lower_bound(aa);
	        auto itc2=ma.lower_bound(-aa);
	        if(itb1!=b.end() && itc2!=ma.end())
	        {
	            ans=min(ans,calc(aa,abs(*itb1),abs(*itc2)));
	        }
	        if(itc1!=a.end() && itb2!=mb.end())
	        {
	            ans=min(ans,calc(aa,abs(*itc1),abs(*itb2)));
	        }
	    }
		cout<<ans<<endl;
	}
    return 0;
}


//252908XL

/*
comments:-

*/
