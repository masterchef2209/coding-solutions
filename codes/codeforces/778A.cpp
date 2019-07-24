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

string s,t;
vector<ll>arr(200005);

bool check(ll pos)
{
	set<ll>ss;
	for(ll i=0;i<=pos;i++)
	{
		ss.insert(arr[i]-1);
	}
	ll j=0;
	for(ll i=0;i<s.size() && j<t.size();i++)
	{
		if(ss.find(i)!=ss.end())
		{
			continue;
		}
		if(t[j]==s[i])
			j++;
	}
	return (j==(t.size()));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s>>t;
	for(ll i=0;i<s.size();i++)
	{
		cin>>arr[i];
	}
	ll lo=0,hi=s.size();
	if(!check(0))
	{
		cout<<0;
		return 0;
	}
	while(lo<hi)
	{
		ll mid=lo+(hi-lo+1)/2;
		if(check(mid))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	cout<<(lo+1);
    return 0;
}


//252908XL