		/*Read the problem carefully before starting to work on it*/

//not accpepted

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
	ll x,n;
	cin>>x>>n;
	set<ll>ss;
	ss.insert(0);
	ss.insert(x);
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	priority_queue< pair<ll,pair<ll,ll> >>pq;
	pq.push(mp(x,mp(0,x)));
	for(ll i=0;i<n;i++)
	{
		auto it2=ss.upper_bound(arr[i]);
		auto it1=prev(it2);
		
		
	//	cout<<*it1<<" "<<*it2<<endl;
		
		
		
		while(!pq.empty())
		{
			pair<ll, pair<ll,ll> >pp=pq.top();
			if(pp.se.fi==(*it1) && pp.se.se==(*it2))
			{
				pq.pop();
			}
			else
				break;
		}
		ss.insert(arr[i]);
		pq.push(mp(arr[i]-(*it1),mp(*it1,arr[i])));
		pq.push(mp((*it2)-arr[i],mp(arr[i],*it2)));
		cout<<(pq.top().fi)<<" ";
		
		
		//cout<<endl;
	}
    return 0;
}


//252908XL