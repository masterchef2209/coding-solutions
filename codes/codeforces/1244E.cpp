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
	ll n,k;
	cin>>n>>k;
	vector<ll>arr(n+3,0);
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin()+1,arr.begin()+n+1);
	ll ans=arr[n]-arr[1];
    // we have divided points into two parts and as size of set of points moved together increases the price of increasing the pointer increases, as we have divided sets into 2 parts making the loop to run till n/2 is enough, also it is optimal to move a pointer of faster speed than slower speed
    for(ll i=1;i<=(n/2);i++)
    {
        ll val1=(arr[i+1]-arr[i])*i;
        ll val2=(arr[n-i+1]-arr[n-i])*i;
        if(k<val1)
        {
            ans-=(k/i);
            break;
        }
        k-=val1;
        ans-=arr[i+1]-arr[i];
        if(k<=0)
            break;
        if(k<val2)
        {
            ans-=(k/i);
            break;
        }
        k-=val2;
        ans-=arr[n-i+1]-arr[n-i];
        if(k<=0)
            break;
    }
    cout<<max(0LL,ans);
    return 0;
}


//252908XL