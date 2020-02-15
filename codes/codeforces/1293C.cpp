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

ll n,q;

ll grid[3][100005];
set< pair<ll,ll> >dat;

ll fl=0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(ll u=0;u<q;u++)
	{
		ll r,c;
		cin>>r>>c;
		grid[r][c]^=1;
		if(grid[r][c]==1)
		{
			for(ll i=max(c-1,1LL);i<=min(c+1,n);i++)
			{
				if(grid[3-r][i]==1)
				{
					fl=1;
					ll one=c;
					ll two=i;
					if(r==2)
					{
						swap(one,two);
					}
					dat.insert(mp(one,two));
				}
			}
		}
		else
		{
			for(ll i=max(c-1,1LL);i<=min(c+1,n);i++)
			{
				ll one=c;
				ll two=i;
				if(r==2)
				{
					swap(one,two);
				}
				if(dat.find(mp(one,two))!=dat.end())
				{
					dat.erase(dat.find(mp(one,two)));
				}
			}
			if(dat.empty())
			{
				fl=0;
			}
		}
		if(fl==0)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
    return 0;
}


//252908XL