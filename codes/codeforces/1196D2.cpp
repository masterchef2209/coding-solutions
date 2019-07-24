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
	ll q;
	cin>>q;
	while(q--)
	{
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		string s1("RGB");
		ll pre1[s.size()+1]={0},pre2[s.size()+1]={0},pre3[s.size()+1]={0};
		ll pos1=0,pos2=1,pos3=2;
		for(ll i=1;i<=n;i++)
		{
			if(s[i-1]==s1[pos1])
			{
				pre1[i]=pre1[i-1];
			}
			else
			{
				pre1[i]=pre1[i-1]+1;
			}
			if(s[i-1]==s1[pos2])
			{
				pre2[i]=pre2[i-1];
			}
			else
			{
				pre2[i]=pre2[i-1]+1;
			}
			if(s[i-1]==s1[pos3])
			{
				pre3[i]=pre3[i-1];
			}
			else
			{
				pre3[i]=pre3[i-1]+1;
			}
			pos1=(pos1+1)%3;
			pos2=(pos2+1)%3;
			pos3=(pos3+1)%3;
		}
		ll ans=INT_MAX;
		for(ll i=k;i<=n;i++)
		{
			ans=min(ans,pre1[i]-pre1[i-k]);
			ans=min(ans,pre2[i]-pre2[i-k]);
			ans=min(ans,pre3[i]-pre3[i-k]);
		}
		cout<<ans<<"\n";
	}
    return 0;
}


//252908XL