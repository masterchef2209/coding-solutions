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

ll dp[110][110][2];
char grid[110][110];

#define INF (1LL<<29)

void fill_dp()
{
    for(ll i=0;i<110;i++)
    {
        for(ll j=0;j<110;j++)
        {
            dp[i][j][0]=INF;
            dp[i][j][1]=INF;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill_dp();
	ll h,w;
	cin>>h>>w;
	for(ll i=1;i<=h;i++)
	for(ll j=1;j<=w;j++)
	{
	    cin>>grid[i][j];
	}
	if(grid[1][1]=='.')
	{
	    dp[1][1][0]=0;
	}
	else
	{
	    dp[1][1][1]=1;
	}
	for(ll i=1;i<=h;i++)
	{
	    for(ll j=1;j<=w;j++)
	    {
	        if(grid[i][j]=='#')
	        {
	            if(i>1)
	            {
	                dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
	                dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
	            }
	            if(j>1)
	            {
	                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+1);
	                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]);
	            }
	        }
	        else
	        {
	            if(i>1)
	            {
	                dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]);
	                dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]);
	            }
	            if(j>1)
	            {
	                dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][0]);
	                dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][1]);
	            }
	        }
	       
	    }
	}
	cout<<min(dp[h][w][0],dp[h][w][1]);
    return 0;
}


//252908XL