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

ll n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector< pair<ll,ll> >arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i].fi;
	}
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i].se;
	}
	sort(arr.begin(),arr.end());
	ll ans=0;
	for(ll i=0;i<n;)
	{
		priority_queue<ll>pq;
		ll curr=arr[i].fi;
		ll j=i;
		ll sum=0;
		while(1){
		while(j<n && arr[j].fi<=curr)
		{
			pq.push(arr[j].se);
			sum+=arr[j].se;
			j++;
		}
		if(pq.empty())
			break;
		sum-=pq.top();
		pq.pop();
		ans+=sum;
		curr++;
		}
		i=j;
	}
	cout<<ans;
    return 0;
}


//252908XL