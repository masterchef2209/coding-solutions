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

map<ll,ll>mm;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<ll>arr(n);
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		ll dat=arr[i];
		vector< pair<ll,ll> >data;
		for(ll j=2;j*j<=arr[i];j++)
		{
			ll cnt=0;
			while(dat%j==0)
			{
				cnt++;
				dat/=j;
			}
			data.eb(j,cnt);
		}
		if(dat>1)
			data.eb(dat,1);
		ll curr=1;
		ll reqd=1;
		ll flag=0;
		for(auto &x:data)
		{
			ll ff=x.fi;
			ll ss=x.se;
			ss%=k;
			if(ss==0)
				continue;
			ll ss1=k-ss;
			for(ll j=0;j<ss;j++)
				curr*=ff;
			for(ll j=0;j<ss1;j++)
			{
				reqd*=ff;
				if(reqd>100000)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag==0)
			ans+=mm[reqd];
		mm[curr]++;
	}
	cout<<ans;
    return 0;
}


//252908XL