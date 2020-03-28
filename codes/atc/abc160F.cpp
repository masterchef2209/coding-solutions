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
#define mod 1000000007LL

double PI=3.1415926535897932384626;

template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

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

#define SSIZE 200005

ll n;
vector< vector<ll> >adj(SSIZE);
ll dp[SSIZE];
ll ssize[SSIZE];
ll fac[SSIZE];
ll ans[SSIZE];

void dfs(ll curr,ll par)
{
	ssize[curr]=1;
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		dfs(nei,curr);
		ssize[curr]+=ssize[nei];
	}
}

void dfs1(ll curr,ll par)
{
	if(adj[curr].size()==1 && par!=-1)
	{
		dp[curr]=1;
		return;
	}
 	ll huh=1;
 	ll bigg=ssize[curr]-1;
	for(auto &nei:adj[curr])
	{
		if(nei==par)
			continue;
		dfs1(nei,curr);
		huh*=dp[nei];
		huh%=mod;
		ll num=fac[bigg];
		ll den1=fac[bigg-ssize[nei]];
		ll den2=fac[ssize[nei]];
		ll den=(den1%mod * den2%mod)%mod;
		den=power(den,mod-2LL);
		num=(num%mod * den%mod)%mod;
		huh*=num;
		huh%=mod;
		bigg-=ssize[nei];
	}
	dp[curr]=huh%mod;
}

void dfs2(ll curr,ll par)
{
    ans[curr]=dp[curr];
    for(auto &nei:adj[curr])
    {
        if(nei==par)
            continue;
        ll prevdpnei=dp[nei];
        ll prevdpcurr=dp[curr];
        ll prevsnei=ssize[nei];
        ll prevscurr=ssize[curr];
        ll num=fac[n-1];
        ll den=(fac[ssize[nei]]%mod * fac[n-1-ssize[nei]]%mod)%mod;
        den=power(den,mod-2LL);
        num=(num%mod * den%mod)%mod;
        num=(num%mod * dp[nei]%mod)%mod;
        num=power(num,mod-2LL);
        dp[curr]=(dp[curr]%mod * num%mod)%mod;
        ssize[curr]-=ssize[nei];
        ssize[nei]=n;
        ll num1=fac[n-1];
        ll den1=(fac[ssize[curr]]%mod * fac[n-1-ssize[curr]]%mod)%mod;
        den1=power(den1,mod-2);
        num1=(num1%mod * den1%mod)%mod;
        num1=(num1%mod * dp[curr]%mod)%mod;
        dp[nei]=(dp[nei]%mod * (num1)%mod)%mod;
        dfs2(nei,curr);
        dp[nei]=prevdpnei;
        dp[curr]=prevdpcurr;
        ssize[nei]=prevsnei;
        ssize[curr]=prevscurr;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0]=1;
	for(ll i=1;i<SSIZE;i++)
	{
		fac[i]=(fac[i-1]%mod * i%mod)%mod;
	}
	cin>>n;
	for(ll i=0;i<(n-1);i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	dfs(1,-1);
	dfs1(1,-1);
	dfs2(1,-1);
	for(ll i=1;i<=n;i++)
	{
	    cout<<ans[i]<<endl;
	}
    return 0;
}


//252908XL

/*
comments:-
really nice problem, number of possible heaps with 1 to n labels along with rerooting.
*/
