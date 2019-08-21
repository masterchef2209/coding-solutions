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
	vector<ll>arr(n+10,0),prefix(n+10,0),suf(n+10,0);
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
		prefix[i]=prefix[i-1]+arr[i];
	}
	for(ll i=n-k;i>=0;i--)
	{
		suf[i+1]=max(suf[i+2],prefix[i+k]-prefix[i]);
	}
	ll one=-1,two=-1,cry=INT_MIN,hehe=-1;
	for(ll i=1;i<=n-2*k+1;i++)
	{
		ll j=i+k-1;
		if((suf[j+1]+prefix[j]-prefix[i-1])>cry)
		{
			one=i;
			hehe=suf[j+1];
			cry=suf[j+1]+prefix[j]-prefix[i-1];
		}
	}
	for(ll u=one+k;u<=n;u++)
	{
		if((prefix[u+k-1]-prefix[u-1])==hehe)
		{
			two=u;
			break;
		}
	}
	cout<<one<<" "<<two<<"\n";
    return 0;
}


//252908XL