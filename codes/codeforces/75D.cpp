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

struct littlearr{
	vector<ll>arr;
	ll suf=INT_MIN;
	ll sum=0;
	ll pre=INT_MIN;
	ll ans=0;
	ll size;
};

ll n,m;

ll dp[250050][3];
ll bigarr[250050];

vector< littlearr >vv(52);

void fill_dp()
{
    for(ll i=1;i<=m;i++)
    {
        dp[i][0]=INT_MIN;
        dp[i][1]=INT_MIN;
        dp[i][2]=INT_MIN;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	for(ll u=1;u<=n;u++)
	{
		ll ssize;
		cin>>ssize;
		vv[u].size=ssize;
		vv[u].sum=0;
		ll dpsum=0,dpmax=INT_MIN;
		for(ll i=0;i<ssize;i++)
		{
			ll tem;
			cin>>tem;
			vv[u].arr.eb(tem);
			vv[u].sum+=tem;
			vv[u].pre=max(vv[u].pre,vv[u].sum);
			if(i==0)
			{
			    dpsum=tem;
			}
			else
			{
			    dpsum=max(dpsum+tem,tem);
			    dpmax=max(dpmax,dpsum);
			}
		}
		vv[u].ans=dpmax;
		ll desum=0;
		for(ll i=ssize-1;i>=0;i--)
		{
			desum+=vv[u].arr[i];
			vv[u].suf=max(vv[u].suf,desum);
		}
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>bigarr[i];
	}
	fill_dp();
	ll pans=INT_MIN;
	for(ll i=1;i<=m;i++)
	{
	    pans=max(pans,vv[bigarr[i]].ans);
	    
	    dp[i][0]=vv[bigarr[i]].suf;
	    
	    dp[i][1]=max(dp[i][1],max(dp[i-1][0],dp[i-1][1])+vv[bigarr[i]].sum );
	    
	    dp[i][2]=max(dp[i][2],max(dp[i-1][0],dp[i-1][1])+vv[bigarr[i]].pre );
	    
	}
	
	for(ll i=1;i<=m;i++)
	{
	    pans=max(pans,dp[i][0]);
	    pans=max(pans,dp[i][1]);
	    pans=max(pans,dp[i][2]);
	}
	
	cout<<pans;
	
    return 0;
}


//252908XL