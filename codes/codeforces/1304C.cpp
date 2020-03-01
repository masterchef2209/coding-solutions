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
	ll q;
	cin>>q;
	while(q--)
	{
		ll n,m;
		cin>>n>>m;
		map< ll , pair<ll,ll> >mm;
		ll fl=0;
		for(ll i=0;i<n;i++)
		{
			ll t,l,h;
			cin>>t>>l>>h;
			if(mm.find(t)==mm.end())
			{
				mm[t]=mp(l,h);
			}
			else
			{
				mm[t].fi=max(mm[t].fi,l);
				mm[t].se=min(mm[t].se,h);
				if(mm[t].se<mm[t].fi)
				{
					fl=1;
				}	
			}
		}
		if(fl)
		{
			cout<<"NO\n";
			continue;
		}
		ll upp=m;
		ll dnn=m;
		ll prevt=0;
		for(auto &x:mm)
		{
			ll t=x.fi;
			pair<ll,ll>ran=x.se;
			ll diff=t-prevt;
			ll upp1=min(ran.se,upp+diff);
			ll dnn1=max(ran.fi,dnn-diff);
			if(dnn1>upp1)
			{
				fl=1;
				break;
			}
			prevt=t;
			upp=upp1;
			dnn=dnn1;
		}
		if(fl)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
    return 0;
}


//252908XL