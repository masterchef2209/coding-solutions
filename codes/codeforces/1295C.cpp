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
		string s,t;
		cin>>s>>t;
		set<char> gg;
		ll fl=0;
		for(ll i=0;i<s.size();i++)
		{
			gg.insert(s[i]);
		}
		for(ll i=0;i<t.size();i++)
		{
			if(gg.find(t[i])==gg.end())
			{
				fl=1;
				break;
			}
		}
		if(fl)
		{
			cout<<"-1\n";
			continue;
		}
		vector< set<ll> >data(26);
		for(ll i=0;i<s.size();i++)
		{
			data[s[i]-'a'].insert(i);
		}
		ll prev=-1;
		ll ans=1;
		for(ll i=0;i<t.size();)
		{
			ll hh=t[i]-'a';
			if(data[hh].lower_bound(prev+1)==data[hh].end())
			{
				ans++;
				prev=-1;
			}
			else
			{
				prev=*data[hh].lower_bound(prev+1);
				i++;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}


//252908XL