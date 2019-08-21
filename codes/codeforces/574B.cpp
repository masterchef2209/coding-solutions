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

vector< set<ll> >gg(4005);

vector< pair<ll,ll> >edges;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(ll u=0;u<m;u++)
	{
		ll a,b;
		cin>>a>>b;
		if(a!=b)
		{
			gg[a].insert(b);
			gg[b].insert(a);
			edges.eb(a,b);
		}
	}
	ll flag=0;
	ll ans=INT_MAX;
	for(auto &e:edges)
	{
		ll one=e.fi;
		ll two=e.se;
		for(auto &three:gg[one])
		{
			if(three!=two && gg[three].find(two)!=gg[three].end())
			{
			    flag=1;
				ll val=(gg[one].size()-2)+(gg[two].size()-2)+(gg[three].size()-2);
				ans=min(ans,val);
			}
		}
	}
	if(flag)
	    cout<<ans;
	else 
	    cout<<-1;
    return 0;
}


//252908XL