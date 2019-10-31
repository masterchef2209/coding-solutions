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
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		deque<ll>doo,de;
		for(ll i=0;i<s.size();i++)
		{
			ll val=s[i]-'0';
			if(val&1)
			{
				doo.pb(val);
			}
			else
			{
				de.pb(val);
			}
		}
		while(!doo.empty() && !de.empty())
		{
			ll val1=doo.front();
			ll val2=de.front();
			if(val1<val2)
			{
				cout<<val1;
				doo.pop_front();
			}
			else
			{
				cout<<val2;
				de.pop_front();
			}
		}
		while(!doo.empty())
		{
			cout<<doo.front();
			doo.pop_front();
		}
		while(!de.empty())
		{
			cout<<de.front();
			de.pop_front();
		}
		cout<<"\n";
	}
    return 0;
}


//252908XL