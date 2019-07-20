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

#define M 5000005

ll arr[M+2];
ll prefix[M+2];
ll sfactor[M+2];

void precompute()
{
	for(ll i=2;i*i<=M;i++)
	{
	    if(sfactor[i]==0)
	    {
	        for(ll j=2*i;j<=M;j+=i)
	        {
	            sfactor[j]=i;
	        }
	    }
	}
	
	for(ll i=2;i<=M;i++)
	{
	    if(sfactor[i]==0)
	    {
	        sfactor[i]=i;
	    }
	    arr[i]=arr[(i/sfactor[i])]+1;
	    prefix[i]=prefix[i-1]+arr[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<prefix[a]-prefix[b]<<"\n";
	}
    return 0;
}