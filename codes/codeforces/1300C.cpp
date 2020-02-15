		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

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
	ll n;
	cin>>n;
	vector<ll>arr(n);
	vector<ll>arr1(n);
	vector<ll>pref(n);
	vector<ll>suf(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		arr1[i]=~arr[i];
	}
    pref[0]=arr1[0];
    for(ll i=1;i<n;i++)
    {
        pref[i]=pref[i-1]&arr1[i];
    }
    suf[n-1]=arr1[n-1];
    for(ll i=n-2;i>=0;i--)
    {
        suf[i]=suf[i+1]&arr1[i];
    }
    ll mm=LLONG_MIN,pos=-1;
    for(ll i=0;i<n;i++)
    {
        ll val;
        if(i==0)
        {
            val=suf[i+1];
        }
        else if(i==(n-1))
        {
            val=pref[i-1];
        }
        else
        {
            val=pref[i-1]&suf[i+1];
        }
        ll val1=arr[i]&val;
        if(val1>mm)
        {
            mm=val1;
            pos=i;
        }
    }
    cout<<arr[pos]<<" ";
    for(ll i=0;i<n;i++)
    {
        if(i==pos)
            continue;
        cout<<arr[i]<<" ";
    }
	return 0;
}


//252908XL