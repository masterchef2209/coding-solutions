		/*Read the problem carefully before starting to work on it*/

// I love digit DP <3

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

ll k;

ll dp[1005][2][1005];

void fill_dp()
{
	for(ll i=0;i<1005;i++)
		for(ll j=0;j<2;j++)
			for(ll k=0;k<1005;k++)
				dp[i][j][k]=-1;
}

bool check(ll n)
{
	ll cc=1;
	while(n>1)
	{
		cc++;
		n=bip(n);
	}
	return (cc==k);
}

ll solve(string s,ll index,ll eq,ll c)
{
	if(index==(s.size()))
	{
	    if(c==0)
	        return 0;
		if(check(c))
			return 1;
		else
			return 0;
	}
	if(dp[index][eq][c]!=-1)
		return dp[index][eq][c];
	ll limit=1;
	if(eq)
	{
		limit=(s[index]-'0');
	}
	ll res=0;
	for(ll d=0;d<=limit;d++)
	{
		ll eq1;
		ll c1=c;
		if(d<(s[index]-'0'))
			eq1=0;
		else
			eq1=eq;
		if(d==1)
			c1=c+1;
		res=(res%mod+solve(s,index+1,eq1,c1)%mod)%mod;
	}
	dp[index][eq][c]=res;
return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	cin>>k;
	// too much case work
	// if k==0 only 0000001 satisfy it
	if(k==0)
	{
	    cout<<1;
	    return 0;
	}
	fill_dp();
	// what is happening here is we will get 1 extra in ans in case of k==1 because 0000001 is included in 1 operation as per our solution but as it only needs 0 operaions it must be excluded
	if(k==1)
	    cout<<solve(s,0,1,0)-1;
	else
	    cout<<solve(s,0,1,0);
    return 0;
}