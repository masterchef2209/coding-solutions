		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		vector<ll>arr(n);
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ll val=arr[0];
		for(ll i=1;i<n;i++)
		{
			ll val1=i*arr[i];
			if(val1<=d)
			{
				d-=val1;
				val+=arr[i];
			}
			else
			{
				for(ll k=arr[i];k>=0;k--)
				{
					ll val2=i*k;
					if(val2<=d)
					{
						val+=k;
						d-=val2;
						break;
					}
				}
			}
		}
		cout<<val<<endl;
	}
    return 0;
}


//252908XL