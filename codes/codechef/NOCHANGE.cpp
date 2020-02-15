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
	    ll n,p;
	    cin>>n>>p;
	    vector<ll>arr(n);
	    for(ll i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    ll pos=-1;
	    vector<ll>ans(n,0);
	    for(ll i=0;i<n;i++)
	    {
	        if(p%arr[i]!=0)
	        {
	            pos=i;
	            break;
	        }
	    }
	    if(pos==-1)
	    {
	        sort(arr.begin(),arr.end());
	        ll pos1=-1;
	        for(ll i=0;i<(n-1);i++)
	        {
	           if(arr[i+1]%arr[i]!=0)
	           {
	               pos1=i;
	               break;
	           }
	        }
	        if(pos1==-1)
	        {
	            cout<<"NO\n";
	        }
	        else
	        {
	            cout<<"YES ";
	            ans[pos1+1]=1;
	            p-=arr[pos1+1];
	            ll qq=p/arr[pos1];
	            qq++;
	            ans[pos1]=qq;
	            for(ll i=0;i<n;i++)
	            {
	                cout<<ans[i]<<" ";
	            }
	            cout<<"\n";
	        }
	    }
	    else
	    {
	        cout<<"YES ";
	        ll val=arr[pos];
	        ll qq=p/val;
	        qq++;
	        ans[pos]=qq;
	        for(ll i=0;i<n;i++)
	        {
	            cout<<ans[i]<<" ";
	        }
	        cout<<"\n";
	    }
	}
    return 0;
}


//252908XL