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
	ll u,v;
	cin>>u>>v;
	if(u==0 && v==0)
	{
	    cout<<0<<endl;
	    return 0;
	}
	if(u>v)
	{
		cout<<-1<<endl;
		return 0;
	}
	ll one=u;
	ll two=v-u;
	if(two==0)
	{
	    cout<<1<<endl;
		cout<<one;
		return 0;
	}
	if(two&1)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		ll three=two/2;
		ll fl=0;
		for(ll i=0;i<64;i++)
		{
			if((three>>i)&1LL)
			{
				if((one>>i)&1LL)
				{
					fl=1;
					break;
				}
			}
		}
		if(fl)
		{
		    cout<<3<<endl;
			cout<<one<<" "<<three<<" "<<three<<endl;
		}
		else
		{
		    cout<<2<<endl;
			cout<<(one+three)<<" "<<three<<endl;
		}
	}
    return 0;
}


//252908XL