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
		ll n;
		cin>>n;
		vector<ll>a(n);
		vector<ll>b(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		for(ll i=0;i<n;i++)
			cin>>b[i];
		ll ph=0,fl=0,diff=-1,bulb=0;
		for(ll i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				if(ph==1)
				{
					fl=1;
					break;
				}
				ll k=b[i]-a[i];
				if(k<0)
				{
					fl=1;
					break;
				}
				else
				{
					if(diff==-1)
					{
						diff=k;
					}
					else
					{
						if(diff==k)
						{
						}
						else
						{
							fl=1;
							break;
						}
					}
				}
				bulb=1;
			}
			else
			{
				if(bulb==1)
				{
					ph=1;
				}
			}
		}
		if(fl)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
    return 0;
}


//252908XL