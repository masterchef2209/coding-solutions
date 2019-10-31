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
	ll a1,a2;
	cin>>a1>>a2;
	ll k1,k2;
	cin>>k1>>k2;
	ll n;
	cin>>n;
	ll tem1=max(0LL,(n-a1*(k1-1)-a2*(k2-1)) );
	cout<<tem1<<" ";
	ll tem2=0;
	ll tem=0;
	ll temm=0;
	if(k1>k2)
	{
	    swap(k1,k2);
	    swap(a1,a2);
	}
	for(ll i=1;i<=a1;i++)
	{
		if(tem2>n)
			break;
		tem=temm;
		temm++;
		tem2+=k1;
	}
	if(tem2>n)
	{
	    cout<<tem;
	    return 0;
	}
	for(ll i=1;i<=a2;i++)
	{
		if(tem2>n)
			break;
		tem=temm;
		temm++;
		tem2+=k2;
	}
	if(tem2>n)
	{
	    cout<<tem;
	}
	else
	{
        cout<<temm;
	}
    return 0;
}


//252908XL