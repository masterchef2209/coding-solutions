		/*Read the problem carefully before starting to work on it*/

//partially correct
		
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
	ll t;
	cin>>t;
	for(ll test=1;test<=t;test++)
	{
		cout<<"Case #"<<test<<": ";
		ll n,g,m;
		cin>>n>>g>>m;
		vector< pair<ll,ll> >G(g);
		for(ll u=0;u<g;u++)
		{
			ll pos;
			char dir;
			cin>>pos>>dir;
			if(dir=='A')
				G[u]=mp(pos,1);
			else
				G[u]=mp(pos,0);
		}
		vector<ll>ans(g,0);
		vector< vector<ll> >rem(n+1);
		for(ll i=0;i<g;i++)
		{
		    rem[G[i].fi].eb(i);
		}
		for(ll u=0;u<m;u++)
		{
			map<ll,vector<ll> >mm;
			for(ll i=0;i<g;i++)
			{
				ll pos=G[i].fi;
				if(G[i].se==1)
				{
					pos--;
					if(pos==0)
						pos=n;
				}
				else
				{
					pos++;
					if(pos==(n+1))
						pos=1;
				}
				mm[pos].eb(i);
				G[i].fi=pos;
			}
			for(auto &x:mm)
			{
				rem[x.fi].clear();
				for(auto &y:x.se)
				{
					rem[x.fi].eb(y);
				}
			}
		}
		for(ll i=1;i<=n;i++)
		{
			for(auto &no:rem[i])
			{
				ans[no]++;
			}
		}
		for(ll i=0;i<g;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
    return 0;
}


//252908XL