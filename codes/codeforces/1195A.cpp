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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector< ll >need(k,0);
	for(ll i=1;i<=n;i++)
	{
		ll tem;
		cin>>tem;
		tem--;
		need[tem]++;
	}
	double cry=n;
	ll limit=ceil(cry/2);
	ll ans=0;
	for(ll i=0;i<k;i++)
	{
		ll req=need[i]/2;
		if(limit==0)
			break;
		ans+=(req*2);
		limit-=(req);
		need[i]-=(req*2);
	}
	for(ll i=0;i<k;i++)
	{
		if(limit==0)
			break;
		ans+=(need[i]);
		limit-=need[i];
	}
	cout<<ans;
    return 0;
}