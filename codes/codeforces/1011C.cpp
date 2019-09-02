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

ll n,m;

ll A[1005];
ll B[1005];

bool check(double fuel)
{
	double weight=m+fuel;
	double used=(weight/B[1]);
	fuel-=used;
	if(fuel<0)
		return false;
	for(ll i=2;i<=n;i++)
	{
		double weight=m+fuel;
		double used=(weight/A[i]);
		fuel-=used;
		if(fuel<0)
			return false;
		weight=m+fuel;
		used=(weight/B[i]);
		fuel-=used;
		if(fuel<0)
			return false;
	}
	weight=m+fuel;
	used=(weight/A[1]);
	fuel-=used;
	if(fuel<0)
		return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>A[i];
	for(ll i=1;i<=n;i++)
		cin>>B[i];
	double lo=0,hi=1e9+1;
	while((hi-lo)>=(1e-6) )
	{
		double mid=(lo+hi)/2;
		if(check(mid))
		{
			hi=mid;
		}
		else
		{
			lo=mid;
		}
	}
	cout<<fixed<<setprecision(10);
	if(hi>=(1e9+1))
	    cout<<-1;
	else
	    cout<<hi;
    return 0;
}


//252908XL