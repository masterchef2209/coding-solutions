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
#define int long long
ll n,k;

string smasknum[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
ll masknum[10];
 
ll mask[2005];
 
map<ll,ll>cry;
 
ll binaryToDecimal(string n) 
{ 
    string num = n; 
    ll dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    ll base = 1; 
  
    ll len = num.length(); 
    for (ll i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 
 
bool dp[2005][2005];
vector<string>data;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(ll i=0;i<10;i++)
	{
		masknum[i]=binaryToDecimal(smasknum[i]);
		cry[masknum[i]]=i;
	}
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		data.eb(s);
		mask[i]=binaryToDecimal(s);
	}
	dp[n][0]=true;
	for(ll i=n-1;i>=0;i--)
	{
		for(ll j=0;j<=k;j++)
		{
			if(!dp[i+1][j])
				continue;
			for(ll dig=9;dig>=0;dig--)
			{	
				if((mask[i]|masknum[dig])==masknum[dig])
				{
					ll diff=__builtin_popcount(mask[i]^masknum[dig]);
					if((j+diff)<=k)
					{
						dp[i][j+diff]|=dp[i+1][j];
					}
				}
			}
		}
	}
	string ans("");
	for(ll i=0;i<n;i++)
	{
		for(ll dig=9;dig>=0;dig--)
		{
			if((mask[i]|masknum[dig])==masknum[dig])
			{
				ll diff=__builtin_popcount(mask[i]^masknum[dig]);
				if(dp[i+1][k-diff])
				{
					ans+=((char)(dig+'0'));
					k=k-diff;
					break;
				}
			}
		}
	}
	if(ans.size()<n)
	{
		cout<<-1;
	}
	else
	{
		cout<<ans;
	}
    return 0;
}
 
 
//252908XL
 
/*
comments:-
 
*/