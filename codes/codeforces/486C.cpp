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
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	ll ssize=s.size();
	ll minlimit,maxlimit;
	if(p<=(ssize/2))
	{
		minlimit=p;
		maxlimit=p;
		ll c=0;
		for(ll i=1;i<=(ssize/2);i++)
		{
			ll j=i-1;
			if(s[j]!=s[n-j-1])
			{
			    int one=(s[j]-'a');
			    int two=(s[n-j-1]-'a');
				c+=min(abs(one-two),26-abs(one-two));
				minlimit=min(minlimit,i);
				maxlimit=max(maxlimit,i);
			}
		}
		ll side1=(p-minlimit);
		ll side2=(maxlimit-p);
		if(side1>side2)
			swap(side1,side2);
		cout<<(c+2*side1+side2);
	}
	else
	{
		minlimit=p;
		maxlimit=p;
		ll c=0;
		for(ll i=(ssize/2)+1;i<=ssize;i++)
		{
			ll j=i-1;
			if(s[j]!=s[n-j-1])
			{
				int one=(s[j]-'a');
			    int two=(s[n-j-1]-'a');
				c+=min(abs(one-two),26-abs(one-two));
				minlimit=min(minlimit,i);
				maxlimit=max(maxlimit,i);
			}
		}
		ll side1=(p-minlimit);
		ll side2=(maxlimit-p);
		if(side1>side2)
			swap(side1,side2);
		cout<<(c+2*side1+side2);
	}
    return 0;
}