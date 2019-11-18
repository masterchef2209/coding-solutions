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
	ll k;
	cin>>k;
	while(k--)
	{
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		map<char,ll>mm;
		for(ll i=0;i<n;i++)
		{
			mm[s[i]]++;
		}
		for(ll i=0;i<n;i++)
		{
			mm[t[i]]++;
		}
		int flag=0;
		for(auto &x:mm)
		{
			if(x.se%2==1)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		vector< pair<ll,ll> >swwap;
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]!=t[i])
			{
				for(ll j=i+1;j<s.size();j++)
				{
					if(s[i]==s[j])
					{
						swap(t[i],s[j]);
						swwap.eb(j+1,i+1);
						break;
					}
					if(s[i]==t[j])
					{
						swap(s[j],t[j]);
						swwap.eb(j+1,j+1);
						swap(t[i],s[j]);
						swwap.eb(j+1,i+1);
						break;
					}
				}
			}
		}
		cout<<(swwap.size())<<"\n";
		for(auto &x:swwap)
		{
			cout<<x.fi<<" "<<x.se<<"\n";
		}
	}
    return 0;
}


//252908XL