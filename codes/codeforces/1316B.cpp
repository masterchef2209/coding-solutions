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
		string s;
		cin>>s;
		map< string, vector<ll> >mm;
		ll pn=n&1;
		for(ll k=1;k<=n;k++)
		{
			ll pk=k&1;
			string pre("");
			string suf("");
			pre=s.substr(k-1,n-(k-1));
			if(k>1)
			{
				suf=s.substr(0,k-1);
			}
			if(pk==pn)
				reverse(suf.begin(),suf.end());
			pre+=suf;
			mm[pre].eb(k);
		}
		vector<ll> &lol=(mm.begin())->se;
		cout<<(mm.begin())->fi <<endl;
		cout<<lol[0]<<endl;
	}
    return 0;
}


//252908XL