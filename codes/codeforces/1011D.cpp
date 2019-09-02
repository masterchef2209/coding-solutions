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

ll m,n;

ll p[35];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>m>>n;
	for(ll i=0;i<n;i++)
	{
		cout<<1<<endl;
		cin>>p[i];
		if(p[i]==0)
		{
			return 0;
		}
	}
	// this is so cool, gives TLE if lo=1
	ll lo=2,hi=m;
	ll cry=0;
	while(1)
	{
		ll mid=(lo+hi)/2;
		cout<<mid<<endl;
		ll tmp;
		cin>>tmp;
		tmp*=p[cry];
		cry=(cry+1)%n;
		if(tmp==0)
		{
			break;
		}
		else if(tmp==1)
		{
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
    return 0;
}


//252908XL