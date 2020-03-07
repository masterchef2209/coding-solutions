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
	ll n;
	cin>>n;
	vector<ll>r(n),b(n);
	for(ll i=0;i<n;i++)
	{
		cin>>r[i];
	}
	ll lol=0;
	for(ll j=0;j<n;j++)
	{
		cin>>b[j];
		lol+=abs(r[j]-b[j]);
	}
	if(lol==0)
	{
		cout<<-1;
		return 0;
	}
	ll lo=1,hi=1e9;
	while(lo<hi)
	{
		ll mid=lo+(hi-lo)/2;
		ll one=0,two=0;
		for(ll i=0;i<n;i++)
		{
			if(r[i]==1 && b[i]==0)
			{
				one+=mid;
			}
			else if(r[i]==0 && b[i]==1)
			{
				two+=1;
			}
			else
			{
			}
		}
		if(one>two)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	if(lo==1e9)
	{
	    cout<<-1;
	    return 0;
	}
	cout<<lo;
    return 0;
}


//252908XL