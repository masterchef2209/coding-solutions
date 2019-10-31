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
	ll q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		string s("");
		ll tem1=n;
		while(tem1>0)
		{
			ll val=tem1%3;
			char one=('0'+val);
			s=one+s;
			tem1/=3;
		}
		s=("0"+s);
		ll pos=0;
		while(pos< s.size() && s[pos]!='2')
			pos++;
		if(pos==(s.size()))
		{
			cout<<n<<"\n";
			continue;
		}
		while(pos>=0 && s[pos]!='0')
		{
			pos--;
		}
		s[pos]='1';
		pos++;
		while(pos<(s.size()))
		{
			s[pos]='0';
			pos++;
		}
		reverse(s.begin(),s.end());
		ll ans=0;
		ll hehe=1;
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				ans+=hehe;
			}
			hehe*=3;
		}
		cout<<ans<<"\n";
	}
    return 0;
}


//252908XL