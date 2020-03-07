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
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	while(true)
	{
	string lol(s.begin(),s.end());
	for(char ch='z';ch>='a';ch--)
	{
	    for(ll tukka=0;tukka<100;tukka++)
		for(ll i=0;i<s.size();)
		{
			if(s[i]=='a')
			{
			    i++;
				continue;
			}
			if(s[i]==ch && ((i-1>=0 && s[i-1]==(ch-1))||(i+1<n && s[i+1]==(ch-1)) ))
			{
				ans++;
				string s1("");
				s1=s.substr(0,i);
				string s2("");
				if((i+1)<n)
					s2=s.substr(i+1,s.size()-i-1);
				s=s1+s2;
			}
			else
			{
				i++;
			}
		}
	}
	if(lol==s)
		break;
	}
	cout<<ans;
    return 0;
}


//252908XL