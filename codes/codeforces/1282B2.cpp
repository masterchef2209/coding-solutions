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
		ll n,p,k;
		cin>>n>>p>>k;
	    vector<ll>arr(n);
	    for(ll i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    if(p<arr[0])
	    {
	        cout<<"0\n";
	        continue;
	    }
	    ll lo=1,hi=n;
	    ll fuck=0;
	    while(lo<hi)
	    {
	        ll mid=lo+(hi-lo+1)/2;
	        //check
	        ll sum=0;
	        ll pos=mid-1;
	        while(pos>=0)
	        {
	            sum+=arr[pos];
	            pos-=k;
	        }
	        if(sum<=p)
	        {
	            lo=mid;
	        }
	        else
	        {
	            hi=mid-1;
	        }
	    }
	    while(lo>=0)
	    {
	        ll pos=lo-1;
	        ll sum=0;
	        while(pos>=(k-1))
	        {
	            sum+=arr[pos];
	            pos-=k;
	        }
	        while(pos>=0)
	        {
	            sum+=arr[pos];
	            pos-=1;
	        }
	        if(sum<=p)
	            break;
	        lo--;
	    }
	    cout<<lo<<"\n";
	}
    return 0;
}


//252908XL