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
#define mod 998244353
 
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
 
#define SSIZE 3005
 
string s,t;
 
ll dp[SSIZE][SSIZE];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s>>t;
	ll n=s.size();
	ll m=t.size();
    for(ll i=m-1;i<=(n-1);i++)
    {
        if(i>(m-1) || s[i]==t[m-1])
        {
            dp[i][0]=1;
        }
        if(s[i]==t[0])
        {
            dp[i][1]=1;
        }
    }
	for(ll i=n-1;i>=0;i--)
	{
		for(ll j=0;j<=(n-1-i);j++)
		{
			if((j+1)>m || t[j]==s[i])
			{
				dp[i][j+1]+=dp[i+1][j];
				dp[i][j+1]%=mod;
			}
			ll k=(n-1-i)-j;
			ll index=n-1-k;
			if((index+1)>m || t[index]==s[i])
			{
				dp[i][j]+=dp[i+1][j];
				dp[i][j]%=mod;
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=n;i++)
	{
		ans+=dp[0][i];
		ans%=mod;
	}
	cout<<ans;
    return 0;
}
 
 
//252908XL
 
/*
comments:-
 
*/