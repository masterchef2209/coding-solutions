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

vector< pair<ll,ll> >data;
ll n,s;
bool check(ll num)
{
	ll cnt=0,cnt2=0;
	for(ll i=0;i<data.size();i++)
	{
		if(data[i].fi>=num)
			cnt++;
		else if(data[i].fi<num && data[i].se>=num)
			cnt2++;
	}
	ll hehe=max(0LL,(n+1)/2-cnt);
	ll sum=0;
	ll hehe1=cnt2-hehe;
	for(ll i=0;i<data.size();i++)
	{
		if(data[i].fi>=num)
			sum+=data[i].fi;
		else if(data[i].fi<num && data[i].se>=num)
		{
		    if(hehe1>0)
		    {
		        sum+=data[i].fi;
		        hehe1--;
		    }
		    else
		    {
		        sum+=num;
		    }
		    
		}
		else
		{
		    sum+=data[i].fi;
		}
	}
	if(sum>s)
	    return false;
	if(hehe<=cnt2)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		data.clear();
		
		cin>>n>>s;
		for(ll u=0;u<n;u++)
		{
			ll l,r;
			cin>>l>>r;
			data.eb(l,r);
		}
		sort(data.begin(),data.end());
		ll lo=data[(n)/2].fi;
		ll hi=2e14;
		while(lo<hi)
		{
			ll mid=lo+(hi-lo+1)/2;
			if(check(mid))
			{
				lo=mid;
			}
			else
			{
				hi=mid-1;
			}
		}
		cout<<lo<<"\n";
	}
    return 0;
}


//252908XL