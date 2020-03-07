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
		ll n;
		cin>>n;
		vector<ll>arr(n);
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ll hehe=-1;
		for(ll i=0;i<n;i++)
		{
			if(arr[i]%2==0)
			{
				hehe=i+1;
				break;
			}
		}
		if(hehe!=-1)
		{
			cout<<1<<endl;
			cout<<hehe<<endl;
			continue;
		}
		ll hehe1=-1,hehe2=-1;
		for(ll i=0;i<n;i++)
		{
			if(hehe1==-1 && arr[i]%2==1)
			{
				hehe1=i+1;
			}
			else if(hehe1!=-1 && arr[i]%2==1)
			{
				hehe2=i+1;
				break;
			}
		}
		if(hehe1!=-1 && hehe2!=-1)
		{
			cout<<2<<endl;
			cout<<hehe1<<" "<<hehe2<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
    return 0;
}


//252908XL