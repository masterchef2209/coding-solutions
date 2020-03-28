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
 
long double PI=3.1415926535897932384626;
 
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
 
#define arctan atan
 
long double getangle(long double x,long double y)
{
    if(x==0)
    {
        if(y>0)
            return (PI/2);
        else
            return (3*PI)/2;
    }
    if(y==0)
    {
        if(x>0)
            return 0;
        else
            return PI;
    }
    if(x>0 && y>0)
    {
        x=abs(x);
        y=abs(y);
        return arctan(y/x);
    }
    else if(x<0 && y>0)
    {
        x=abs(x);
        y=abs(y);
        return (PI-arctan(y/x));
    }
    else if(x<0 && y<0)
    {
        x=abs(x);
        y=abs(y);
        return (PI+arctan(y/x));
    }
    else if(x>0 && y<0)
    {
        x=abs(x);
        y=abs(y);
        return ((PI)+(PI-arctan(y/x)));
    }
}

ll n;
vector< pair<long double,ll> >data,data1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		long double x,y;
		cin>>x>>y;
		long double ang=getangle(x,y);
		long double ang1=2*PI-ang;
		data.eb(mp(ang,i));
		data1.eb(mp(ang1,i));
	}
	sort(data.begin(),data.end());
	sort(data1.begin(),data1.end());
	ll xx=-1,yy=-1;
	long double val=LLONG_MAX;
	for(ll i=0;i<(2*n);i++)
	{
	    ll k=i%n;
	    ll j=(i+1)%n;
		long double val1=abs(data[j].fi-data[k].fi);
		if(val1>PI)
		{
		    val1=2*PI-val1;
		}
		if(val1<val)
		{
			val=val1;
			xx=data[k].se;
			yy=data[j].se;
		}
		long double val2=abs(data1[j].fi-data1[k].fi);
		if(val2>PI)
		{
		    val2=2*PI-val2;
		}
		if(val2<val)
		{
			val=val2;
			xx=data1[k].se;
			yy=data1[j].se;
		}
	}
	cout<<xx<<" "<<yy;
    return 0;
}
 
 
//252908XL