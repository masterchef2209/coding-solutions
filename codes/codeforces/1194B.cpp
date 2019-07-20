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
		ll n,m;
		cin>>n>>m;
		char grid[n+1][m+1];
		ll cx[n+1];
		ll cy[m+1];
		vector<ll>bagx,bagy;
		ll mx=-1;
		ll my=-1;
		for(ll i=1;i<=n;i++)
		{
			ll c=0;
			for(ll j=1;j<=m;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='*')
					c++;
			}
			cx[i]=c;
			mx=max(mx,c);
		}
		for(ll i=1;i<=n;i++)
		{
		    if(cx[i]==mx)
		        bagx.eb(i);
		}
		for(ll i=1;i<=m;i++)
		{
			ll c=0;
			for(ll j=1;j<=n;j++)
			{
				if(grid[j][i]=='*')
					c++;
			}
			cy[i]=c;
			my=max(my,c);
		}
		for(ll i=1;i<=m;i++)
		{
		    if(cy[i]==my)
		        bagy.eb(i);
		}
		ll ans=(m-mx)+(n-my);
		int flag=0;
		for(auto &one:bagx)
		{
		    if(flag)
		        break;
		    for(auto &two:bagy)
		    {
		        if(grid[one][two]=='.')
		        {
		            ans--;
		            flag=1;
		            break;
		        }
		    }
		    if(flag)
		        break;
		}
		cout<<ans<<"\n";
	}
    return 0;
}