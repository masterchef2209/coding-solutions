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
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll n=s.size();
		set<ll>ss;
		for(ll i=0;i<n;i++)
		{
			if(s[i]=='R')
				ss.insert(i+1);
		}
		ss.insert(n+1);
		ll lo=1,hi=n+1;
		while(lo<hi)
		{
			ll mid=lo+(hi-lo)/2;
			ll pos=0;
			ll fl=0;
			//cout<<mid<<endl;
			while(pos<=(n+1))
			{
			    //cout<<pos<<" ";
				auto it=ss.upper_bound(pos+mid);
				if(it==ss.begin())
				{
				    fl=1;
				    break;
				}
				it--;
				ll val=*it;
				if(val>pos && val<=(pos+mid))
				{
					pos=val;
				}
				else
				{
					fl=1;
					break;
				}
			}
		//	cout<<endl;
			if(pos==(n+1))
			{
			    hi=mid;
			}
			else
			{
			    lo=mid+1;
			}
		}
		cout<<lo<<endl;
	}
    return 0;
}


//252908XL