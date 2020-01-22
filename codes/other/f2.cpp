		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

//not accepted

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

#define SSIZE 55
#define INF (1LL<29)

ll n,d,p,k;

ll dp[SSIZE][SSIZE*100][2];
ll D[SSIZE];
ll D1[SSIZE];
ll P[SSIZE];
ll P1[SSIZE];

void fill_dp()
{
    for(ll i=0;i<SSIZE;i++)
    for(ll p=0;p<(SSIZE*100);p++)
    for(ll k=0;k<2;k++)
        dp[i][p][k]=INF;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>d>>p>>k;
	fill_dp();
	for(ll i=1;i<=n;i++)
	{
	    cin>>D[i];
	}
	D[n+1]=d;
	for(ll i=n;i>=0;i--)
	{
	    D1[i+1]=D[i+1]-D[i];
	}
	for(ll i=1;i<=n;i++)
	{
	    cin>>P[i];
	}
	P1[0]=p;
	for(ll i=1;i<=(n+1);i++)
	{
	    P1[i]=P1[i-1]+P[i];
	}
	dp[0][p][0]=0;
	dp[0][p][1]=0;
// 	for(ll i=0;i<=(n+1);i++)
// 	{
// 	    cout<<D1[i]<<" ";
// 	}
// 	cout<<endl;
// 	for(ll i=0;i<=(n+1);i++)
// 	{
// 	    cout<<P1[i]<<" ";
// 	}
// 	cout<<endl;
	for(ll i=1;i<=(n+1);i++)
	{
	    for(ll p=0;p<=P1[i];p++)
	    {
	        ll one=INF;
	        if( (p-D1[i])>=0)
	        one=min(one,dp[i-1][p-D1[i]][0]);
	        if( (p-D1[i])>=0)
	        one=min(one,dp[i-1][p-D1[i]][1]);
	        ll one1=INF;
	        if( (p-D1[i]+P[i-1])>=0 && P[i-1]>0)
	        one1=min(one1,dp[i-1][p-D1[i]+P[i-1]][0]);
	        if( (p-D1[i]+P[i-1])>=0 && P1[i-1]>0)
	        one1=min(one1,dp[i-1][p-D1[i]+P[i-1]][1]);
	        one1+=k;
	        dp[i][p][1]=one+D1[i];
	        dp[i][p+P[i-1]][1]=one1+D1[i];
	        ll lone=INF;
	        if( (p)>=0)
	        lone=min(lone,dp[i-1][p][0]);
	        if( (p)>=0)
	        lone=min(lone,dp[i-1][p][1]);
	        ll lone1=INF;
	        if( (p+P[i-1])>=0 && P[i-1]>0)
	        lone1=min(lone1,dp[i-1][p+P[i-1]][0]);
	        if( (p+P[i-1])>=0 && P[i-1]>0)
	        lone1=min(lone1,dp[i-1][p+P[i-1]][1]);
	        lone1+=k;
	        dp[i][p][0]=lone+5*D1[i];
	        dp[i][p+P[i-1]][0]=lone1+5*D1[i];
	    }
	}
	ll ans=INF;
	    for(ll pe=0;pe<=P1[n+1];pe++)
	    {
	        for(ll v=0;v<2;v++)
	        {
	            ans=min(ans,dp[n+1][pe][v]);
	        }
	    }
	    cout<<ans<<endl;
    return 0;
}


//252908XL