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
	ll n;
	cin>>n;
	vector<ll>arr(n);
	set<ll>ss;
	for(ll i=1;i<=n;i++)
	{
		ss.insert(i);
	}
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		if(ss.find(arr[i])!=ss.end())
		{
			ss.erase(ss.find(arr[i]));
		}
	}
	vector<ll>bag;
	for(ll i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			if(ss.find(i+1)!=ss.end())
			{
				bag.eb(i);
			}
		}
	}
	if(bag.size()==1)
	{
	    for(ll i=0;i<n;i++)
	    {
	        if(i!=bag[0] && arr[i]==0)
	        {
	            arr[i]=(bag[0]+1);
	            ss.erase(bag[0]+1);
	            break;
	        }
	    }
	    
	}
	else
	{
	    for(ll i=0;i<bag.size();i++)
	    {
		    ll j=bag[i];
		    ll k=bag[(i+1)%((ll)bag.size())];
		    arr[j]=k+1;
		    ss.erase(k+1);
	    }
	}
	for(ll i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			arr[i]=(*ss.begin());
			ss.erase(ss.begin());
		}
	}
	for(ll i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
    return 0;
}


//252908XL
