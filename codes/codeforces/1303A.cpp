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
		string s;
		cin>>s;
		ll fl=0;
		ll cc=0;
		ll ans=0;
		for(ll i=0;i<s.size();i++)
		{
			if(fl==0 && s[i]=='1')
			{
				fl=1;
			}
			if(fl)
			{
				if(s[i]=='0')
					cc++;
				else
				{
					ans+=cc;
					cc=0;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}


//252908XL