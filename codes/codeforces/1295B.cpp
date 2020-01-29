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
	    ll n,x;
	    cin>>n>>x;
	    string s;
	    cin>>s;
	    ll arr[n+10]={0};
	    set<ll>ss;
	    ll one=0,zero=0;
	    for(ll i=0;i<n;i++)
	    {
	        if(s[i]=='1')
	            one++;
	        else
	            zero++;
	        arr[i]=zero-one;
	        ss.insert(arr[i]);
	    }
	    ll l=arr[n-1];
	    ll ans=0;
	    if(l==0 && ss.find(x)!=ss.end())
	    {
	        cout<<"-1\n";
	        continue;
	    }
	    if(l==0)
	    {
	        cout<<"0\n";
	        continue;
	    }
	    for(ll i=0;i<n;i++)
	    {
	        ll haha=x-arr[i];
	        if( (haha*l)<0)
	            continue;
	        if(haha%l==0)
	            ans++;
	    }
	    if(x==0)
	        ans++;
	    cout<<ans<<endl;
	}
    return 0;
}


//252908XL