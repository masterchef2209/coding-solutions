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
 
vector<ll>arr(2000005,0),s(2000005,0),d(2000005,0);
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;	
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
		s[i]=arr[i];
	}
	sort(s.begin()+1,s.begin()+n+1);
	for(ll u=0;u<k;u++)
	{
		ll a,b;
		cin>>a>>b;
		if(arr[a]<arr[b])
			d[b]++;
		if(arr[b]<arr[a])
			d[a]++;
	}
	for(ll i=1;i<=n;i++)
	{
		cout<< lower_bound(s.begin()+1,s.begin()+n+1,arr[i])-(s.begin()+1)-d[i]<<" ";
	}
    return 0;
}