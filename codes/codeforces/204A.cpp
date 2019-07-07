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

ll dp[20][2][10][10];

void fill_dp()
{
	for(ll i=0;i<20;i++)
		for(ll j=0;j<2;j++)
			for(ll k=0;k<10;k++)
			    for(ll k1=0;k1<10;k1++)
				dp[i][j][k][k1]=-1;
}

ll solve(string s,int index,int eq,int l,int r)
{
	if(index==s.size())
	{
		if(l==r && l!=0)
			return 1;
		return 0;
	}
	if(dp[index][eq][l][r]!=-1)
		return dp[index][eq][l][r];
	int limit=9;
	ll ret=0;
	if(eq)
	{
	    limit=(s[index]-'0');
	}
	for(ll d=0;d<=limit;d++)
	{
	    int eq1;
	    int l1;
	    int r1;
	    if(d<(s[index]-'0'))
	    {
	        eq1=0;
	    }
	    else
	    {
	        eq1=eq;
	    }
	    if(l==0 && d!=0)
	        l1=d;
	    else
	        l1=l;
	    r1=d;
	    ret+=solve(s,index+1,eq1,l1,r1);
	}
	dp[index][eq][l][r]=ret;
return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b;
	cin>>a>>b;
	string a1=to_string(a-1);
	string b1=to_string(b);

	fill_dp();
	ll num1=solve(b1,0,1,0,0);

	fill_dp();
	ll num2=0;
	if(b>1)
	    num2=solve(a1,0,1,0,0);

	cout<<num1-num2;
    return 0;
}