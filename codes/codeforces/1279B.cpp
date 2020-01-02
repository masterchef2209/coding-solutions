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
		ll n;
		cin>>n;
		ll s;
		cin>>s;
		vector<ll>arr(n);
		ll sum=0;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum<=s)
		{
			cout<<0<<"\n";
			continue;
		}
		ll sum1=0,pos=-1;
		for(ll i=0;i<n;i++)
		{
			sum1+=arr[i];
			if(sum1>s)
			{
				sum1-=arr[i];
				pos=i;
				break;
			}
		}
		if(pos==0)
		{
		    cout<<1<<endl;
		    continue;
		}
		ll hehe=pos;
		ll hehe1=0;
		ll val=max_element(arr.begin(),arr.begin()+pos+1)-arr.begin();
		ll sum2=0,pos2=-1,fl=0;
		for(ll i=0;i<n;i++)
		{
			if(i==val)
			{
				fl=i+1;
				continue;
			}
			hehe1++;
			sum2+=arr[i];
			if(sum2>s)
			{
				sum2-=arr[i];
				hehe1--;
				pos2=i;
				break;
			}
		}
		if(hehe1>=hehe)
		    cout<<fl<<"\n";
		else
		{
		    cout<<0<<"\n";
		}
	}
    return 0;
}


//252908XL