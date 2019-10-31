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
 
#define SSIZE 1000006
 
ll A[SSIZE];
ll F[SSIZE];
ll n,k;
bool check(ll num)
{
	ll sum=0;
	for(ll i=1;i<=n;i++)
	{
		sum+=max(0LL,A[i]-(num/F[i]));
	}
	if(sum<=k)
		return true;
	return false;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>F[i];
	}
	sort(A+1,A+n+1,greater<ll>());
	sort(F+1,F+n+1);
	ll lo=0,hi=-1;
	for(ll i=1;i<=n;i++)
	{
	    hi=max(hi,A[i]*F[i]);
	}
	while(lo<hi)
	{
		ll mid=lo+(hi-lo)/2;
		if(check(mid))
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<lo;
    return 0;
}
 
 
//252908XL