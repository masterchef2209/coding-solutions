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

ll n,m;
vector<ll>arr(200);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	while(m--)
	{
	    auto compare= [](pair<ll,ll>lhs,pair<ll,ll>rhs)
	    {
	        if(lhs.fi==rhs.fi)
	        {
	            return lhs.se>rhs.se;
	        }
	        else
	        {
	            return lhs.fi<rhs.fi;
	        }
	    };
		priority_queue< pair<ll,ll>, vector< pair<ll,ll> > ,decltype(compare) >pq(compare);
		for(ll i=0;i<n;i++)
		{
			pq.push(mp(arr[i],i+1));
		}
		ll k,pos;
		cin>>k>>pos;
		multiset< pair<ll,ll> >mm; 
		ll kh=k;
		while(kh--)
		{
			pair<ll,ll> val=pq.top();
			pq.pop();
			mm.insert(mp(val.se,val.fi));
		}
		auto it=mm.begin();
		pos--;
		while(pos--)
		{
			it++;
		}
		cout<<(it->se)<<"\n";
	}
    return 0;
}


//252908XL