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
 
#define SIZE 1000006
 
ll timeline[SIZE],query[SIZE];
 
ll t[100005],k[100005],d[100005];
 
ll occupied[101];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,q;
	cin>>n>>q;
	for(ll u=0;u<q;u++)
	{
		cin>>t[u]>>k[u]>>d[u];
		query[t[u]]=u+1;
	}
	ll av=n;
	for(ll tim=1;tim<SIZE;tim++)
	{
	    ll kek=timeline[tim];
		av+=timeline[tim];
		for(ll i=1;i<101;i++)
		{
		    if(kek==0)
		        break;
		    if(occupied[i]==tim)
		    {
		        occupied[i]=0;
		        kek--;
		    }
		    if(kek==0)
		        break;
		}
		if(query[tim]==0)
			continue;
		ll pos=query[tim]-1;
		ll t1=t[pos];
		ll k1=k[pos];
		ll d1=d[pos];
		if(k1>av)
		{
			cout<<"-1\n";
		}
		else
		{
		    //print
		    ll hehe=0,pos1=1;
		    ll kek=k1;
		    while(pos1<101)
		    {
		        if(kek==0)
		            break;
		        if(occupied[pos1]==0)
		        {
		            occupied[pos1]=(t1+d1);
		            hehe+=pos1;
		            kek--;
		        }
		        if(kek==0)
		            break;
		        pos1++;
		    }
		    cout<<hehe<<"\n";
			av-=k1;
			timeline[t1+d1]+=k1;
		}
	}
    return 0;
}
 
 
//252908XL