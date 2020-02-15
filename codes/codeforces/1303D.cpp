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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<ll>arr(m);
		for(ll i=0;i<m;i++)
		{
			cin>>arr[i];
			arr[i]=log2(arr[i]);
		}
		vector<ll>av(64,0);
		for(ll i=0;i<m;i++)
		{
		    av[arr[i]]++;
		}
		vector<ll>need;
		for(ll i=0;i<64;i++)
		{
			if((n>>i)&1LL)
				need.eb(i);
		}
		ll ans=0;
		ll fl=0;
		for(ll i=0;i<need.size();i++)
		{
			ll val=need[i];
			for(ll j=0;j<val;j++)
			{
				av[j+1]+=(av[j]/2);
				av[j]%=2;
			}
			if(av[val]>0)
			{
				av[val]--;
				continue;
			}
			for(ll j=val+1;j<64;j++)
			{
				if(av[j])
				{
					ans+=(j-val);
					av[j]--;
					for(ll k=j-1;k>val;k--)
					{
						av[k]++;
					}
					av[val]+=2;
					break;
				}
			}
			if(av[val]>0)
			{
				av[val]--;
			}
			else
			{
				fl=1;
				break;
			}
		}
		if(fl)
			cout<<"-1\n";
		else
			cout<<ans<<endl;
	}
    return 0;
}


//252908XL