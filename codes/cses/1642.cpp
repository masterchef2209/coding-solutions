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
	vector<ll>v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector< pair<ll, pair<ll,ll> > >arr;
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			arr.eb(mp( (v[i]+v[j]),mp(i+1,j+1) ) );
		}
	}
	sort(arr.begin(),arr.end());
	for(ll i=0;i<arr.size();i++)
	{
		if(arr[i].fi>(x/2))
			break;
		auto it=lower_bound(arr.begin()+i+1,arr.end(),mp(x-arr[i].fi,mp(LLONG_MIN,LLONG_MIN)));
		while((it->fi+arr[i].fi)==x)
		{
			ll p1,p2,q1,q2;
			p1=arr[i].se.fi;
			p2=arr[i].se.se;
			q1=(it->se).fi;
			q2=(it->se).se;
			if(p1==q1 || p1==q2 || p2==q1 || p2==q2)
			{
				it++;
				continue;
			}
			cout<<p1<<" "<<p2<<" "<<q1<<" "<<q2;
			return 0;
		}
	}
	cout<<"IMPOSSIBLE";
    return 0;
}


//252908XL