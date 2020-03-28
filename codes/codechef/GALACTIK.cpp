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

ll n,m;

#define SSIZE 100005

#define int long long

int parent[SSIZE];
int size[SSIZE];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

map<ll,ll>mm;

set<ll>ss;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=0;i<=n;i++)
	{
		make_set(i);
	}
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		if(find_set(a)!=find_set(b))
		    union_sets(a,b);
	}
	ll woohoo=LLONG_MAX;
	for(ll i=0;i<=n;i++)
	{
	    parent[i]=find_set(i);
	}
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		if(x>=0)
		    woohoo=min(woohoo,x);
		if(x<0)
			x=LLONG_MAX-1;
		ll y=find_set(i);
		ss.insert(y);
		if(mm.find(y)==mm.end())
		{
		    mm[y]=x;
		}
		else
		{
		    mm[y]=min(mm[y],x);
		}
	}
	ll ans=0;
	ll fl=0;	
	for(auto &z:mm)
	{
	    if(z.se==LLONG_MAX-1)
	    {
	        fl=1;
	        break;
	    }
	    else
	    {
	       ans+=z.se;
	    }
	}
	if(ss.size()==1)
	{
		cout<<0;
		return 0;
	}
	if(fl)
	{
		cout<<-1;
		return 0;
	}
	cout<<(ss.size()-2)*woohoo+ans;
    return 0;
}


//252908XL