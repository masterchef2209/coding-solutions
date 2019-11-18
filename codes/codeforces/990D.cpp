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

ll n,a,b;

ll grid[1005][1005];

set< pair<ll,ll> >ss;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>a>>b;
	int flag=0;
	if(b==1)
	{
	    flag=1;
		swap(a,b);
	}
	if(a!=1)
	{
		cout<<"NO\n";
	}
	else
	{
		if((n==2||n==3) && b==1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			ll lol=n-b;
			ll curr=1;
			for(ll i=1;i<=lol;i++)
			{
				ss.insert(mp(curr,curr+1));
				ss.insert(mp(curr+1,curr));
				curr++;
			}
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				{
					if(i==j)
						continue;
					pair<ll,ll>pp=mp(i,j);
					if(ss.find(pp)!=ss.end())
					{
						grid[i][j]=0^flag;
					}
					else
					{
						grid[i][j]=1^flag;
					}
				}
			}
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				{
					cout<<grid[i][j];
				}
				cout<<"\n";
			}
		}
	}
    return 0;
}


//252908XL