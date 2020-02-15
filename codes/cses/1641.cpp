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
	ll n,x;
	cin>>n>>x;
	vector< pair<ll,ll> >arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i].fi;
		arr[i].se=i+1;
	}
	sort(arr.begin(),arr.end());
	
	for(ll i=0;i<n-2;i++)
	{
		if(arr[i].fi>=x)
			break;
		for(ll j=i+1;j<n-1;j++)
		{
			if((arr[i].fi+arr[j].fi)>=x)
				break;
			ll val=x-(arr[i].fi+arr[j].fi);
			auto it=lower_bound(arr.begin()+j+1,arr.end(),mp(val,LLONG_MIN));
			ll val1=it->fi;
			if(val1==val)
			{
				cout<<it->se<<" "<<arr[i].se<<" "<<arr[j].se;
				return 0;
			}
		}
	}		
	cout<<"IMPOSSIBLE";
    return 0;
}


//252908XL