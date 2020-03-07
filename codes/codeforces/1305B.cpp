		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	vector<ll>ans;
	ll n=s.size();
	vector<ll>pre(n,0),suf(n,0);
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='(')
			pre[i]=1;
		else
			suf[i]=1;
	}
	for(ll i=1;i<n;i++)
	{
		pre[i]+=pre[i-1];
	}
	for(ll i=n-2;i>=0;i--)
	{
		suf[i]+=suf[i+1];
	}
	ll pos=-1;
	ll val=0;
	for(ll i=0;i<(n-1);i++)
	{
		ll val1=min(pre[i],suf[i+1]);
		if(val1>val)
		{
			val=val1;
			pos=i;
		}
	}
	if(pos==-1)
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<1<<endl;
		ll one=0,two=0;
		for(ll i=0;i<=pos;i++)
		{
		    if(one>=val)
			    break;
			if(s[i]=='(')
			{
				ans.eb(i+1);
				one++;
			}
			if(one>=val)
			    break;
		}
		for(ll i=n-1;i>pos;i--)
		{
		    if(two>=val)
			    break;
			if(s[i]==')')
			{
				ans.eb(i+1);
				two++;
			}
			if(two>=val)
			    break;
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<endl;
		for(auto &x:ans)
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}
    return 0;
}


//252908XL