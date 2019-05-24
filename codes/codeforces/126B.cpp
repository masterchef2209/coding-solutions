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

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
#define int long long
#define fi first
#define se second

bool cmp(string &a,string &b)
{
	ll a1=a.size();
	ll b1=b.size();
	return a1>b1;
}

vector<int> prefix_function(string &s) 
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	ll n=s.size();
	vector<ll>lps=prefix_function(s);
	for(ll i=0;i<n-1;i++)
	{
		if(lps[i]==lps[n-1] && lps[i]!=0)
		{
			string ans=s.substr(0,lps[n-1]);
			cout<<ans;
			return 0;
		}
	}
	ll len;
	if(lps[n-1]==0)
	    len=0;
	else len=lps[lps[n-1]-1];
	if(len<=0)
	{
	    cout<<"Just a legend";
	    return 0;
	}
	else
	{
		string ans=s.substr(0,lps[lps[n-1]-1]);
		cout<<ans;
	}
    return 0;
}