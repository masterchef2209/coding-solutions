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

ll grid[310][310];

vector< vector< pair<ll,ll> > >tubes(91000);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,k;
	cin>>n>>m>>k;
	ll num=1;
	ll cry=0;
	ll k1=k-1;
	for(ll i=1;i<=n;i++)
	{
	    if(k1<=0)
	        break;
		if(i&1)
		{
			for(ll j=1;j<=m;j++)
			{
			     if(k1<=0)
	                break;
				grid[i][j]=num;
				cry++;
				if(cry==2)
				{
				    k1--;
					cry=0;
					num++;
				}
				 if(k1<=0)
	                break;
			}
		}
		else
		{
			for(ll j=m;j>=1;j--)
			{
			     if(k1<=0)
	                break;
				grid[i][j]=num;
				cry++;
				if(cry==2)
				{
				    k1--;
					cry=0;
					num++;
				}
				 if(k1<=0)
	                break;
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
	    if(i&1)
		for(ll j=1;j<=m;j++)
		{
			tubes[grid[i][j]].eb(i,j);
		}
		else
		for(ll j=m;j>=1;j--)
		{
			tubes[grid[i][j]].eb(i,j);
		}
	}
	for(ll i=0;i<=num;i++)
	{
	    if(!tubes[i].empty())
	    {
	        cout<<tubes[i].size()<<" ";
		    for(auto &pp:tubes[i])
		    {
			    cout<<pp.fi<<" "<<pp.se<<" ";
		    }
		    cout<<"\n";
	    }
	}
    return 0;
}


//252908XL