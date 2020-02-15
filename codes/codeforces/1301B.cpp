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
		vector<ll>arr(n);
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		double sum=0;
		set<ll>ss;
		for(ll i=0;i<n;i++)
		{
			if(arr[i]!=-1)
			{
				if((i+1)<n && arr[i+1]==-1)
					ss.insert(arr[i]);
				if((i-1)>=0 && arr[i-1]==-1)
					ss.insert(arr[i]);
			}
		}
		sum+=(*ss.begin());
		if(ss.size()>1)
		{
		    auto it=ss.end();
		    it--;
		    sum+=(*it);
		}
		if(ss.empty())
		{
		    cout<<0<<" "<<0<<endl;
		    continue;
		}
		if(ss.size()>1)
		    sum/=2.0;
		ll val=round(sum);
		for(ll i=0;i<n;i++)
			if(arr[i]==-1)
				arr[i]=val;
		ll ans=LLONG_MIN;
		for(ll i=0;i<(n-1);i++)
		{
			ll va=abs(arr[i+1]-arr[i]);
			ans=max(ans,va);
		}
		cout<<ans<<" "<<val<<endl;
	}
    return 0;
}
 
 
//252908XL