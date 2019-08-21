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

set<ll>ss;
map<ll,ll>mm;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,I;
	cin>>n>>I;
	ll val=(8*I)/n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		ss.insert(arr[i]);
		mm[arr[i]]++;
	}
	ll lo=1,hi=ss.size();
	while(lo<hi)
	{
		ll mid=lo+(hi-lo+1)/2;
		ll num=ceil(log2(mid));
		if(val>=num)
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	vector<ll>cry;
	cry.eb(0);
	for(auto &no:mm)
	{
		cry.eb(no.se);
	}
	if(lo>=(ss.size()))
	{
		cout<<0;
	}
	else
	{
		for(ll i=1;i<cry.size();i++)
		{
			cry[i]+=cry[i-1];
		}
		ll hehe=INT_MIN;
		for(ll i=1;i<cry.size();i++)
		{
			if(i-lo>=0)
				hehe=max(hehe,cry[i]-cry[i-(lo)]);
		}
		cout<<(n-hehe);
	}
    return 0;
}


//252908XL