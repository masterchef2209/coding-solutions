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
	ll n,m,v;
	cin>>n>>m>>v;
	ll max_edges= (n-1)*(n-2)/2 + 1;
	ll min_edges=n-1;
	if(m>max_edges || m<min_edges)
	{
		cout<<-1;
	}
	else
	{
		ll ccount=0;
		ll v1=(v%n)+1;
		if(ccount>=m)
		{
				return 0;
		}
		cout<<v1<<" "<<v<<endl;
		ccount++;
		if(ccount>=m)
				return 0;
		for(ll i=1;i<=n;i++)
		{
			if(i==v1)
				continue;
			if(ccount>=m)
			{
				return 0;
			}
			for(ll j=i+1;j<=n;j++)
			{
				if(j==v1)
					continue;
				cout<<i<<" "<<j<<endl;
				ccount++;
				if(ccount>=m)
				return 0;
			}
			if(ccount>=m)
				return 0;
		}
	}
    return 0;
}


//252908XL