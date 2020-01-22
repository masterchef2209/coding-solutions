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

#define SSIZE 300005
#define N 10

ll grid[SSIZE][N];

ll n,m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>grid[i][j];
		}
	}
	ll a=1,b=1;
	ll lo=0,hi=1e9;
	while(lo<hi)
	{
		ll mid=lo+(hi-lo+1)/2;
		set<ll>tmp;
		map<ll,ll>mm;
		for(ll i=1;i<=n;i++)
		{
			ll mask=0;
			for(ll j=1;j<=m;j++)
			{
				if(grid[i][j]>=mid)
				{
					mask+=(1LL<<(j-1));
				}
			}
			tmp.insert(mask);
			mm[mask]=i;
		}
		vector<ll>tmp1;
		for(auto &x:tmp)
		{
			tmp1.eb(x);
		}
		ll fl=0;
		for(ll i=0;i<tmp1.size();i++)
		{
			for(ll j=i;j<tmp1.size();j++)
			{
				ll val=tmp1[i]|tmp1[j];
				if(val==((1LL<<m)-1))
				{
					a=mm[tmp1[i]];
					b=mm[tmp1[j]];
					fl=1;
					break;
				}
			}
			if(fl)
				break;
		}
		if(fl==0)
		{
			hi=mid-1;
		}
		else
		{
			lo=mid;
		}
	}
	cout<<a<<" "<<b;
    return 0;
}


//252908XL