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
		ll n,x;
		cin>>n>>x;
		vector<ll>arr(n);
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr.rbegin(),arr.rend());
		ll x1=max(0LL,x-(2*arr[0]) );
		ll val=(x1+(arr[0]-1))/arr[0];
		ll lol=x-(val*arr[0]);
		if(lol==0)
		{
		    cout<<val<<endl;
		    continue;
		}
		ll fl=0;
		for(ll i=0;i<n;i++)
		{
		    if(lol==arr[i])
		    {
		        fl=1;
		        break;
		    }
		}
		if(fl)
		    cout<<val+1<<endl;
		else
		    cout<<val+2<<endl;
	}
    return 0;
}


//252908XL