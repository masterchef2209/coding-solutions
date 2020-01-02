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
	ll t;
	cin>>t;
	while(t--)
	{
		string n;
		cin>>n;
	    ll pre0[1005]={0};
	    ll pre1[1005]={0};
	    pre0[0]=(n[0]=='0');
	    pre1[0]=(n[0]=='1');
	    for(ll i=1;i<n.size();i++)
	    {
	        pre0[i]=pre0[i-1]+(n[i]=='0');
	        pre1[i]=pre1[i-1]+(n[i]=='1');
	    }
	    ll ans=LLONG_MAX;
	    for(ll i=0;i<n.size();i++)
	    {
	        for(ll j=i;j<n.size();j++)
	        {
	            ll val0=pre0[i]+(pre1[j]-pre1[i])+pre0[n.size()-1]-pre0[j];
	            ll val1=pre1[i]+(pre0[j]-pre0[i])+pre1[n.size()-1]-pre1[j];
	            ans=min(val0,ans);
	            ans=min(val1,ans);
	        }
	    }
	    if(ans==LLONG_MAX)
	        cout<<"0\n";
	    else
	        cout<<ans<<"\n";
	}
    return 0;
}


//252908XL