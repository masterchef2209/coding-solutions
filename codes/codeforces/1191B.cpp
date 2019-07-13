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
	string a,b,c;
	cin>>a>>b>>c;
	ll ku,ssu;
	if(a==b && b==c)
		ku=0;
	else if(a==b || b==c || a==c)
		ku=1;
	else
		ku=2;
	if(a[1]!=b[1] && a[1]!=c[1] && b[1]!=c[1])
		ssu=2;
	else if(a[1]==b[1] && b[1]==c[1])
	{
		vector<ll>ha;
		ha.eb(a[0]-'0');
		ha.eb(b[0]-'0');
		ha.eb(c[0]-'0');
		sort(ha.begin(),ha.end());
		if(ha[1]==(ha[0]+1) && ha[2]==(ha[1]+1))
			ssu=0;
		else if(ha[1]==(ha[0]+1) || ha[2]==(ha[1]+1) || ha[1]==(ha[0]+2) || ha[2]==(ha[0]+2) || ha[2]==(ha[1]+2) || ha[2]==(ha[0]+1))
			ssu=1;
		else
			ssu=2;
	}
	else
	{
		ll n1,n2;
		if(a[1]==b[1])
		{
			n1=(a[0]-'0');
			n2=(b[0]-'0');
		}
		else if(b[1]==c[1])
		{
			n1=(b[0]-'0');
			n2=(c[0]-'0');
		}
		else if(a[1]==c[1])
		{
			n1=(a[0]-'0');
			n2=(c[0]-'0');
		}
		if(n1>n2)
			swap(n1,n2);
		if(n2==(n1+1) || n2==(n1+2))
			ssu=1;
		else
			ssu=2;
	}
	cout<<min(ku,ssu);
    return 0;
}