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

ll grid[2010][2010];

ll d1[4020];
ll d2[4020];

priority_queue< pair< ll, pair<ll,ll> > >pq,pq1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>grid[i][j];
			d1[i+j]+=grid[i][j];
			d2[i-j+n-1]+=grid[i][j];
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			ll value=d1[i+j]+d2[i-j+n-1]-grid[i][j];
			if((i+j)%2==0)
				pq.push(mp(value,mp(i+1,j+1)));
			else
				pq1.push(mp(value,mp(i+1,j+1)));
		}
	}
	pair<ll,pair<ll,ll> >one=pq.top();
	pq.pop();
	pair<ll,pair<ll,ll> >two=pq1.top();
	pq1.pop();
	cout<<(one.fi+two.fi)<<"\n";
	cout<<one.se.fi<<" "<<one.se.se<<" "<<two.se.fi<<" "<<two.se.se;
    return 0;
}


//252908XL