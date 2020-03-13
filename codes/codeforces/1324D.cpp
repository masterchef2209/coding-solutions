		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

#define T pair< ll,ll >

typedef tree< T ,null_type,less< T >,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

ost mm;

ll getless(ost &os, ll R, ll index)
{
	return os.order_of_key({R-1, index});
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>a(n,0);
	vector<ll>b(n,0);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
	}
	vector<ll>ba(n,0);
	for(ll i=0;i<n;i++)
	{
		ba[i]=b[i]-a[i];
	}
	ll ans=0;
	ll why=0;
	mm.insert({ba[n-1],why++});
	for(ll i=n-2;i>=0;i--)
	{
		ll val=a[i]-b[i];
		ll hehe=getless(mm, val, 1e9);
		//cout<<val<<" "<<hehe<<endl;
		ans+=hehe;
		mm.insert({ba[i],why++});
	}
	cout<<ans;
    return 0;
}


//252908XL