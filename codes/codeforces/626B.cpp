		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

bool dp[210][210][210];

void f(ll b,ll g,ll r)
{
	if(b<0 || g<0 || r<0)
		return;
	if(dp[b][g][r])
		return;
	dp[b][g][r]=true;
	if(b>1)
		f(b-1,g,r);
	if(g>1)
		f(b,g-1,r);
	if(r>1)
		f(b,g,r-1);
	f(b-1,g-1,r+1);
	f(b+1,g-1,r-1);
	f(b-1,g+1,r-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll b=0,g=0,r=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='B')
			b++;
		else if(s[i]=='G')
			g++;
		else if(s[i]=='R')
			r++;
	}
	f(b,g,r);
	if(dp[1][0][0])
		cout<<"B";
	if(dp[0][1][0])
		cout<<"G";
	if(dp[0][0][1])
		cout<<"R";
    return 0;
}