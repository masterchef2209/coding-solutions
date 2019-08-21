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
 
map<ll,ll>pre,suf;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll u=0;u<n;u++)
	{
		string s;
		cin>>s;
		ll left=0,right=0,flag=0;
		for(ll v=0;v<s.size();v++)
		{
			if(s[v]=='(')
				left++;
			else
				right++;
			if(right>left)
			{
			    flag=1;
			}
		}
		ll left1=0,right1=0,flag1=0;
		for(ll v=s.size()-1;v>=0;v--)
		{
		    if(s[v]=='(')
				left1++;
			else
				right1++;
			if(left1>right1)
			{
			    flag1=1;
			}
		}
		if(flag==0 && left>=right)
		{
		    pre[left-right]++;
		}
		if(flag1==0 && right>=left)
		{
		    suf[right-left]++;
		}
	}
	ll ans=0;
	for(ll i=0;i<=300005;i++)
	{
	    if(pre.find(i)!=pre.end() && suf.find(i)!=suf.end())
	    {
	        ans+=(pre[i]*suf[i]);
	    }
	}
	cout<<ans;
    return 0;
}
 
 
//252908XL