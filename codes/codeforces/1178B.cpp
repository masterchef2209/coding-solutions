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

vector<ll>V,PreV(1000005,0),SufV(1000005,0);
vector<ll>O;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	ll pos=0;
	while(s[pos]=='o' && pos<s.size())
	{
		pos++;
	}
	if(pos==s.size())
	{
		cout<<0;
		return 0;
	}
	ll vc=0,oc=0;
	for(ll i=pos;i<s.size();i++)
	{
	    if(s[i]=='v')
	    {
	        if(vc==0)
	        {
	            O.eb(oc);
	            oc=0;
	        }
	        vc++;
	    }
	    else
	    {
	        if(oc==0)
	        {
	            V.eb(vc-1);
	            vc=0;
	        }
	        oc++;
	    }
	}
	if(vc!=0)
	{
	    V.eb(vc-1);
	}
	PreV[0]=V[0];
	for(ll i=1;i<V.size();i++)
	{
	    PreV[i]=PreV[i-1]+V[i];
	}
	SufV[V.size()-1]=V[V.size()-1];
	for(ll i=V.size()-1;i>=0;i--)
	{
	    SufV[i]=SufV[i+1]+V[i];
	}
	ll ans=0;
	for(int i=1;i<V.size();i++)
	{
	    ans+=(SufV[i]*PreV[i-1]*O[i]);
	}
	cout<<ans;
    return 0;
}


//252908XL