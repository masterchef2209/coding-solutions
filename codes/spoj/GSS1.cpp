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

#define SSIZE 1<<16

struct data{
    ll ts;
    ll ps;
    ll ss;
    ll ans;
    data()
    {
        ts=ps=ss=ans=0;
    }
};

ll n;
ll arr[SSIZE];
data t[2*SSIZE];

data combine(data l,data r)
{
    data ret;
    ret.ts=l.ts+r.ts;
    ret.ss=max(r.ss,r.ts+l.ss);
    ret.ps=max(l.ps,l.ts+r.ps);
    ret.ans=max(max(l.ans,r.ans),l.ss+r.ps);
    return ret;
}

data makedata(ll val)
{
    data ret;
    ret.ts=val;
    ret.ps=ret.ss=ret.ans=val;
    return ret;
}

void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        t[v]=makedata(arr[tl]);
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=combine(t[v*2],t[v*2+1]);
    }
}

data query(ll v,ll l,ll r,ll tl,ll tr)
{
    if(l>r)
    {
        data cry= makedata(-1000000);
        return cry;
    }
    if(r<tl || l>tr)
    {
        data cry= makedata(-1000000);
        return cry;
    }
    if(l<=tl && r>=tr)
    {
        return t[v];
    }
    ll tm=(tl+tr)/2;
    return combine(query(v*2,l,r,tl,tm),query(v*2+1,l,r,tm+1,tr));
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
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(1,l,r,0,n-1).ans<<endl;
    }
    return 0;
}


//252908XL

/*
comments:-

*/
