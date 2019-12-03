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
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll val=0;
		vector< pair<ll,ll> >ans;
		string s1("");
		ll kh=k-1;
		while(kh--)
		{
			s1+="()";
		}
		ll why=n-((k-1)*2);
		if(why>0)
		{
			s1+="(";
			why--;
		}
		while(why>1)
		{
			s1+="()";
			why-=2;
		}
		if(why>0)
		{
			s1+=")";
			why--;
		}
		for(ll i=0;i<n;i++)
		{
			if(s[i]!=s1[i])
			{
			    ll j;
			    for(j=i;j<n;j++)
			    {
			        if(s[j]==s1[i])
			            break;
			    }
			    ans.eb(i+1,j+1);
			    reverse(s.begin()+i,s.begin()+j+1);
			}
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