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

ll arr[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll v;
	cin>>v;
	int flag=1;
	ll minpaint=INT_MAX;
	ll mincolor=-1;
	for(ll i=1;i<=9;i++)
	{
		cin>>arr[i];
		if(arr[i]<=minpaint)
		{
			minpaint=arr[i];
			mincolor=i;
		}
		if(arr[i]<=v)
			flag=0;
	}
	if(flag)
	{
		cout<<-1;
		return 0;
	}
	ll dig=(v/minpaint);
	ll rempaint=(v-dig*minpaint);
	for(ll i=1;i<=9;i++)
	{
		arr[i]-=minpaint;
	}
	string ans("");
	int pos=9;
	while(rempaint>0 && dig>0 && pos>=1)
	{
		while(arr[pos]<=rempaint && rempaint>0 && dig>0 && pos>=1)
		{
			ans+=to_string(pos);
			rempaint-=arr[pos];
			dig--;
		}
		if(pos==mincolor)
			break;
		pos--;
	}
	while(dig--)
	{
		ans+=to_string(mincolor);
	}
	cout<<ans;
    return 0;
}