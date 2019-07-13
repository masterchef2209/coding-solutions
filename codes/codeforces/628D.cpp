/*BE THE HARDEST WORKING PERSON YOU KNOW.*/
		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
typedef int ll;
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
 
int m,d;
 
ll dp[2002][2][2002];
 
void fill_dp()
{
	for(ll i=0;i<2002;i++)
		for(ll j=0;j<2;j++)
			for(ll k=0;k<2002;k++)
				dp[i][j][k]=-1;
}
 
bool check(string s)
{
    ll mmod=0;
	for(ll i=0;i<s.size();i++)
	{
		ll num=s[i]-'0';
		mmod=(10*mmod+num)%m;
		if(i&1)
		{
			if(num!=d)
				return false;
		}
		else
		{
			if(num==d)
				return false;
		}
	}
	if(mmod==0)
        return true;
    else
        return false;
}
 
ll f(string &s,int index,int eq,int mmod)
{
	if(index==s.size())
	{
		if(mmod==0)
			return 1;
		else
			return 0;
	}
	if(dp[index][eq][mmod]!=-1)
		return dp[index][eq][mmod];
	int limit=9;
	if(eq)
	{
		limit=(s[index]-'0');
	}
	ll ret=0;
	if(index&1)
	{
	    if(eq && d>(s[index]-'0'))
	        return 0;
		ll dig=d;
		int eq1;
		int mmod1;
		if(dig<(s[index]-'0'))
		{
			eq1=0;
		}
		else
		{
			eq1=eq;
		}
		mmod1=(mmod*10+dig)%m;
		ret+=f(s,index+1,eq1,mmod1);
		ret%=mod;
	}
	else
	{
		for(ll dig=(index==0)?1:0;dig<=limit;dig++)
		{
			if(dig==d)
				continue;
			int eq1;
			int mmod1;
			if(dig<(s[index]-'0'))
			{
				eq1=0;
			}
			else
			{
				eq1=eq;
			}
			mmod1=(mmod*10+dig)%m;
			ret+=f(s,index+1,eq1,mmod1);
			ret%=mod;
		}
	}
	dp[index][eq][mmod]=ret;
return ret;
	
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>m>>d;
	string a,b;
	cin>>a>>b;
	fill_dp();
	ll num1=f(b,0,1,0);
	fill_dp();
	ll num2=f(a,0,1,0);
	if(check(a))
	{
		cout<<(num1 - num2+1+mod)%mod;
	}
	else
	{
		cout<<(num1 - num2+mod)%mod;
	}
    return 0;
}