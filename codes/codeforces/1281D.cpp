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
	ll t;
	cin>>t;
	while(t--)
	{
		ll r,c;
		ll fll=0;
		cin>>r>>c;
		char grid[r+5][c+5];
		ll lol=0;
		for(ll i=1;i<=r;i++)
		{
			for(ll j=1;j<=c;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='A')
					lol++;
			}
		}
		if(lol==0)
		{
			cout<<"MORTAL\n";
			continue;
		}
		if(lol==(r*c))
		{
		    cout<<"0\n";
		    continue;
		}
		ll hehe=0;
		for(ll i=1;i<=r;i++)
		{
			ll cry=0;
			for(ll j=1;j<=c;j++)
			{
				if(grid[i][j]=='P')
					cry++;
			}
			if(cry==0)
			{
				hehe++;
				if(i==1 || i==r)
				    fll=1;
			}
		}
		for(ll i=1;i<=c;i++)
		{
			ll cry=0;
			for(ll j=1;j<=r;j++)
			{
				if(grid[j][i]=='P')
					cry++;
			}
			if(cry==0)
			{
				hehe++;
				if(i==1 || i==c)
				    fll=1;
			}
		}
		if(hehe>0)
		{
		    if(fll)
		    {
		        cout<<"1\n";
		    }
		    else
			    cout<<"2\n";
			continue;
		}
		if(grid[1][c]=='A' || grid[1][1]=='A' || grid[r][1]=='A' || grid[r][c]=='A')
		{
			cout<<"2\n";
			continue;
		}
		ll why=0;
		for(ll i=2;i<r;i++)
		{
			if(grid[i][1]=='A')
				why++;
			if(grid[i][c]=='A')
				why++;
		}
		for(ll i=2;i<c;i++)
		{
			if(grid[1][i]=='A')
				why++;
			if(grid[r][i]=='A')
				why++;
		}
		if(why>0)
		{
			cout<<"3\n";
			continue;
		}
		cout<<"4\n";
	}
    return 0;
}
 
 
//252908XL