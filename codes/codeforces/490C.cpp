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

vector<ll>pos(1000006,0);
vector<ll>pos1(1000006,0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	ll a,b;
	cin>>a>>b;
	ll mm=0;
	for(ll i=0;i<s.size()-1;i++)
	{
		mm=(mm*10+(s[i]-'0'))%a;
		if(mm==0 && s[i+1]!='0')
		{
			pos[i+1]=1;
		}
	}
	ll mm1=0;
	ll tem=1;
	for(ll i=s.size()-1;i>0;i--)
	{
	    mm1=(mm1+(s[i]-'0')*tem)%b;
	    if(mm1==0)
	    {
	        pos1[i]=1;
	    }
	    tem*=10;
	    tem%=b;
	}
	ll hehe=-1;
	for(ll i=0;i<s.size();i++)
	{
	    if(pos[i]==1 && pos1[i]==1)
	    {
	        hehe=i;
	        break;
	    }
	}
	if(hehe==-1)
	{
	    cout<<"NO";
	}
	else
	{
	    cout<<"YES\n";
	    for(ll i=0;i<hehe;i++)
	    {
	        cout<<s[i];
	    }
	    cout<<"\n";
	    for(ll i=hehe;i<s.size();i++)
	    {
	        cout<<s[i];
	    }
	}
    return 0;
}


//252908XL