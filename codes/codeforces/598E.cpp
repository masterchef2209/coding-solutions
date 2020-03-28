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
#define INF (1LL<<29)
ll dp[32][32][52];

void fill_dp()
{
	for(ll i=0;i<32;i++)
	for(ll j=0;j<32;j++)
	for(ll k=0;k<52;k++)
		dp[i][j][k]=INF;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	fill_dp();
	for(ll i=1;i<32;i++)
	for(ll j=1;j<32;j++)
	{
	    if(i*j<52)
	        dp[i][j][i*j]=0;
	    dp[i][j][0]=0;
	}
	for(ll i=1;i<32;i++)
	{
		for(ll j=1;j<32;j++)
		{
			for(ll k=1;k<min(52LL,i*j);k++)
			{
				ll val=INF;
				for(ll i1=1;i1<i;i1++)
				{
				    for(ll k1=0;k1<=k;k1++)
					    val=min(val,dp[i1][j][k1]+dp[i-i1][j][k-k1]+j*j);
				}
				for(ll j1=1;j1<j;j1++)
				{
				    for(ll k1=0;k1<=k;k1++)
					    val=min(val,dp[i][j1][k1]+dp[i][j-j1][k-k1]+i*i);
				}
				dp[i][j][k]=val;	
			}
		}
	}
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		cout<<dp[n][m][k]<<endl;
	}
    return 0;
}


//252908XL