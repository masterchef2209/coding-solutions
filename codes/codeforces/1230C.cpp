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

ll n,m;

vector< set<ll> >adj(10);
ll grid[10][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].insert(b);
		adj[b].insert(a);
		grid[a][b]=1;
		grid[b][a]=1;
	}
	if(n<=6)
	{
		cout<<m;
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		if(adj[i].empty())
		{
			cout<<m;
			return 0;
		}
	}
	ll ans11=0;
	for(ll pos=1;pos<=7;pos++)
	{
	    ll m1=m-adj[pos].size();
        ll val=0;
        for(ll i=1;i<=7;i++)
        {
            if(i==pos)
                continue;
            ll temp=0;
            for(ll j=1;j<=7;j++)
            {
                if(j==pos)
                    continue;
                if(grid[i][j]==0)
                {
                    if(adj[pos].find(j)!=adj[pos].end())
                        temp++;
                }
            }
            val=max(temp,val);
        }
        ans11=max(val+m1,ans11);
	}
    cout<<ans11;
    return 0;
}


//252908XL