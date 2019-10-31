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
	ll n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	ll ab=0,ba=0;
	queue<ll>vab,vba;
	ll a=0,b=0;
	for(ll i=0;i<n;i++)
	{
		if(s1[i]==s2[i])
			continue;
		if(s1[i]=='a')
		{
			ab++;
			vab.push(i);		
		}
		else
		{
			ba++;
			vba.push(i);
		}
		a++;
		b++;
	}
	if( (a&1)==1 || (b&1)==1  )
	{
		cout<<-1;
	}
	else
	{
		vector< pair<ll,ll> >ans;
		while(vab.size()>1)
		{
			ll one=vab.front();
			vab.pop();
			ll two=vab.front();
			vab.pop();
			ans.eb(one+1,two+1);
		}
		while(vba.size()>1)
		{
			ll one=vba.front();
			vba.pop();
			ll two=vba.front();
			vba.pop();
			ans.eb(one+1,two+1);
		}
		if(vab.size()>0)
		{
			ll one=vab.front();
			vab.pop();
			ll two=vba.front();
			vba.pop();
			ans.eb(one+1,one+1);
			ans.eb(one+1,two+1);
		}
		cout<<(ans.size())<<"\n";
		for(auto &x:ans)
		{
			cout<<x.fi<<" "<<x.se<<"\n";
		}
	}
    return 0;
}


//252908XL