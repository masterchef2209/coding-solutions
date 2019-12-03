		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>A(n);
	auto compare=[](pair<ll,ll>a,pair<ll,ll>b)
	{
		if(a.fi==b.fi)
		{
			return a.se>b.se;
		}
		else
		{
			return a.fi<b.fi;
		}
	};
	//offline processing so cool :O
	priority_queue< pair<ll,ll> , vector< pair<ll,ll> >,decltype(compare) >pq(compare);
	for(ll i=0;i<n;i++)
	{
		cin>>A[i];
		pq.push(mp(A[i],i));
	}
	ll m;
	cin>>m;
	vector< pair<pair<ll,ll>,ll > >data(m);
	for(ll i=0;i<m;i++)
	{
		cin>>data[i].fi.fi>>data[i].fi.se;
		data[i].fi.se--;
		data[i].se=i;
	}
	sort(data.begin(),data.end());
	ost bag;
	vector<ll>ans(m);
	for(ll i=0;i<m;i++)
	{
		ll why=data[i].fi.fi;
		while(bag.size()<why)
		{
			bag.insert(pq.top().se);
			pq.pop();
		}
		ans[data[i].se]=A[*bag.find_by_order(data[i].fi.se)];
	}
	for(ll i=0;i<m;i++)
	{
		cout<<ans[i]<<"\n";
	}
    return 0;
}


//252908XL