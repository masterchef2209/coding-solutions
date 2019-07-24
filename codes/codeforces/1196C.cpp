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
		ll V1=-1e5,V2=1e5,V3=1e5,V4=-1e5;
		for(ll u=0;u<n;u++)
		{
			ll x,y,f1,f2,f3,f4;
			cin>>x>>y>>f1>>f2>>f3>>f4;
			if(f1==0)
				V1=max(V1,x);
			if(f2==0)
				V2=min(V2,y);
			if(f3==0)
				V3=min(V3,x);
			if(f4==0)
				V4=max(V4,y);
		}
	//	cout<<"___"<<V1<<" "<<V2<<" "<<V3<<" "<<V4<<"\n";
		if( (V1<=V3) && (V4<=V2) )
		{
			cout<<1<<" ";
			cout<<V1<<" "<<V4<<"\n";
		}
		else
		{
			cout<<0<<"\n";
		}
	}
    return 0;
}
 
 
//252908XL