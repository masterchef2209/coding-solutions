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
		map<ll,ll>mm;
		for(ll i=0;i<(4*n);i++)
		{
			ll num;
			cin>>num;
			mm[num]++;
		}
		vector<ll>vv,vv1;
		int fl=1;
		for(auto &x:mm)
		{
			if(x.se&1)
			{
				fl=0;
				break;
			}
			vv.eb(x.fi);
			vv1.eb(x.se);
		}
		if(fl==0)
		{
			cout<<"NO\n";
			continue;
		}
		int fl1=1;
		set<ll>ss;
		for(ll i=0;i<vv.size();i++)
		{
			ll j=(vv.size())-i-1;
			if(vv1[i]!=vv1[j])
			{
				fl1=0;
				break;
			}
			ll tem=vv[i]*vv[j];
			ss.insert(tem);
		}
		if(fl1==0)
		{
			cout<<"NO\n";
			continue;
		}
		if(ss.size()==1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
    return 0;
}
 
 
//252908XL