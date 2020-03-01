		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

// not accepted

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

ll f(ll year)
{
	vector<ll>temp={5,10,11,16,21,22,27};
	ll quo=year/28;
	ll rem=year%28;
	auto it=upper_bound(temp.begin(),temp.end());
	if(it==temp.begin())
		return quo*7;
	ll ex=(it-temp.begin());
	return (quo*7+ex);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll m1,m2,y1,y2;
		cin>>m1>>y1>>m2>>y2;
		if(m2==1)
			y2--;
		if(m1>3)
			y1++;
		cout<<f(y2)-f(y1)<<endl;
	}
    return 0;
}


//252908XL