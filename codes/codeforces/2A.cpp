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

vector< pair<string,ll> >queries;
map<string,ll>mm,mm1;
set<string> bag;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll u=0;u<n;u++)
	{
	    string s;
	    ll val;
	    cin>>s>>val;
	    queries.eb(s,val);
	    mm[s]+=val;
	}
	ll tem=INT_MIN;
	for(auto &xx:mm)
	{
	    tem=max(xx.se,tem);
	}
	for(auto &x:mm)
	{
	    if(x.se==tem)
	        bag.insert(x.fi);
	}
	for(auto &q:queries)
	{
	    string s=q.fi;
	    ll val=q.se;
	    mm1[s]+=val;
	    if(mm1[s]>=tem && bag.find(s)!=bag.end())
	    {
	        cout<<s;
	        return 0;
	    }
	}
    return 0;
}


//252908XL