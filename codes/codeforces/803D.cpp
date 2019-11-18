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
 
ll k;
string s,ad;
 
bool check(ll wordsize)
{
    ll rows=0;
    ll curr=0;
    while(curr<(ad.size()) )
    {
        rows++;
       // cout<<curr<<"\n";
        ll en=curr+wordsize-1;
        if(en>=(ad.size())-1)
            break;
        while(ad[en]!=' ' && en>curr)
            en--;
        if(en==curr)
            return false;
        curr=(en+1);
    }
  //  cout<<wordsize<<" "<<rows<<"\n";
    return (rows<=k);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>k;
	getline(cin,s);
	getline(cin,s);
	
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='-')
			ad+=" ";
		else
			ad+=s[i];
	}
	ll lo=1,hi=ad.size();
	while(lo<hi)
	{
	    ll mid=(lo+hi)/2;
	    if(check(mid))
	    {
	        hi=mid;
	    }
	    else
	    {
	        lo=mid+1;
	    }
	}
	cout<<lo;
    return 0;
}
 
 
//252908XL