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

set<ll>ss;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	queue< pair<ll,ll> >Q;
	for(ll i=0;i<n;i++)
	{
		Q.push(mp(arr[i],arr[i]));
		ss.insert(arr[i]);
	}
	vector<ll> ans;
	ll ans1=0;
	while(!Q.empty() && m>0)
	{
		pair<ll,ll>a=Q.front();
		Q.pop();
		if(a.fi!=a.se)
		{
			ans.eb(a.fi);
			m--;
			ans1+=abs(a.fi-a.se);
		}
		ll prev=a.fi-1;
		if(ss.find(prev)==ss.end())
		{
			Q.push(mp(prev,a.se));
			ss.insert(prev);
		}
		ll next=a.fi+1;
		if(ss.find(next)==ss.end())
		{
			Q.push(mp(next,a.se));
			ss.insert(next);
		}
	}
	cout<<ans1<<endl;
	for(auto &x:ans)
	{
		cout<<x<<" ";
	}
    return 0;
}


//252908XL