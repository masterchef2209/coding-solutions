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

ll n;

struct target{
	ll x,y,t;
	double p;
};

bool cmp(target a, target b)
{
	return a.t<b.t;
}

double dp[1010];
vector< target >vv(1010);

double dista(ll i,ll j)
{
	ll delx=abs(vv[i].x-vv[j].x);
	ll dely=abs(vv[i].y-vv[j].y);
	return sqrt(delx*delx+dely*dely);
}

void fill_dp()
{
    for(ll i=0;i<n;i++)
        dp[i]=-1;
}

double f(ll curr)
{
	if(dp[curr]!=-1)
		return dp[curr];
	double ret=0;
	for(ll nxt=curr+1;nxt<n;nxt++)
	{
		if((vv[curr].t+dista(curr,nxt))<=vv[nxt].t)
			ret=max(ret,f(nxt));
	}
	return dp[curr]=(ret+vv[curr].p);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll a,b,c;
		double d;
		cin>>a>>b>>c>>d;
		vv[i]=target{a,b,c,d};
	}
	sort(vv.begin(),vv.begin()+n,cmp);
    fill_dp();
	for(ll i=0;i<n;i++)
		f(i);
	double ans=INT_MIN;
	for(ll i=0;i<n;i++)
		ans=max(ans,dp[i]);
	cout<<fixed<<setprecision(10);
	cout<<ans;
    return 0;
}


//252908XL