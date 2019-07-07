		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream cin("input.txt")
//#define of1 ofstream cout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1,s2;
	while(getline(cin,s1))
	{
		getline(cin,s2);
	//	cout<<s1<<" "<<s2<<endl;
		ll dp[s1.size()+3][s2.size()+3];
		for(ll i=0;i<=s2.size();i++)
		{
		    dp[s1.size()][i]=0;
		}
		for(ll i=0;i<=s1.size();i++)
		{
		    dp[i][s2.size()]=0;
		}
		for(ll i=s1.size()-1;i>=0;i--)
		{
			for(ll j=s2.size()-1;j>=0;j--)
			{
				if(s1[i]==s2[j])
				{
					dp[i][j]=1+dp[i+1][j+1];
				}
				else
				{
					dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
				}
			}
		}
// 		for(ll i=0;i<s1.size();i++)
// 		{
// 		    for(ll j=0;j<s2.size();j++)
// 		    {
// 		        cout<<dp[i][j]<<" ";
// 		    }
// 		    cout<<endl;
// 		}
		cout<<dp[0][0]<<"\n";
	}
    return 0;
}