//dummy dum dum
    /*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
typedef unsigned long long ll;
 
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
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
		cin>>n>>m;
		ll ans;
		if(n&1)
		{
			ans=n*((n+1)/2);
		}
		else
		{
			ans=(n/2)*(n+1);
		}
		n=n-m;
        ll hehe=n/(m+1);
        ll rem=n%(m+1);
        ll alph=0;
        alph+= ( rem*((1+hehe)*(1+hehe+1))/2);
        ll lol=(m+1-rem)*( ((hehe)*(hehe+1))/2 );
        alph+=lol;
		cout<<(ans-alph)<<endl;
	}
    return 0;
}
 
 
//252908XL