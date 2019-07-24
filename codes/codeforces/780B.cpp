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

ll n;
vector<double>X(60005);
vector<double>V(60005);

bool check(double t)
{
	double L=1e10,R=-1e10;
	for(ll i=0;i<n;i++)
	{
		double li=X[i]-V[i]*t;
		double ri=X[i]+V[i]*t;
		L=min(L,li);
		R=max(R,ri);
	}
	if(L<=R)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>X[i];
	for(ll j=0;j<n;j++)
		cin>>V[j];
	double lo=0,hi=1e9+10;
	while((hi-lo)>(1e-6))
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
	cout<<lo;
    return 0;
}


//252908XL