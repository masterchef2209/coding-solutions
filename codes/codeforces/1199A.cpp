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

vector<ll>arr(100005);
ll n,x,y;
bool check(ll pos)
{
	for(ll i=pos-1;i>=max(1LL,pos-x);i--)
	{
		if(arr[i]<=arr[pos])
			return false;
	}
	for(ll i=pos+1;i<=min(n,pos+y);i++)
	{
		if(arr[i]<=arr[pos])
			return false;
	}
return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>x>>y;
	for(ll i=1;i<=n;i++)
		cin>>arr[i];
	for(ll i=1;i<=n;i++)
	{
		if(check(i))
		{
			cout<<i;
			return 0;
		}
	}
    return 0;
}


//252908XL