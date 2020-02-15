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

#define SSIZE 200005

ll n;
string s;
ll ans[SSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	cin>>s;
	multiset< pair<ll,ll> >mm;
	mm.insert(mp(-1,1));
	ll curr=1;
	for(ll i=0;i<s.size();i++)
	{
		ll lol=s[i]-'a';
		auto it=mm.upper_bound(mp(lol,1e9));
		if(it==mm.begin())
		{
			curr++;
			ans[i]=curr;
			mm.insert(mp(lol,curr));
		}
		else
		{
			it--;
			ll tem=it->se;
			ans[i]=tem;
			mm.erase(it);
			mm.insert(mp(lol,tem));
		}
	}
	cout<<curr<<endl;
	for(ll i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}


//252908XL