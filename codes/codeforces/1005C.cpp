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

ll n;
vector<ll>arr(120005);
map<ll,ll>mm;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll tmp;
		cin>>tmp;
		arr[i]=tmp;
		mm[tmp]++;
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
	    ll flag=0;
	    for(ll j=1;j<=(1e10);j*=2)
	    {
	        if(mm.find(j-arr[i])!=mm.end())
	        {
	            if((j-arr[i])==arr[i] && mm[arr[i]]<=1)
	                continue;
	            flag=1;
	            //cout<<arr[i]<<" "<<(j-arr[i])<<endl;
	            break;
	        }
	    }
	    if(flag==0)
	    {
	        ans++;
	    }
	}
	cout<<ans;
    return 0;
}


//252908XL