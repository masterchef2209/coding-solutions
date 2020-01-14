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
#define N 2000006

ll n;

ll t[4*N];

void build(ll a[],ll v,ll tl,ll tr)
{
	if(tl==tr)
	{
		t[v]=a[tl];
	}
	else
	{
		ll tm=(tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v]=0;
	}
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll xx)
{
	if(l>r)
		return;
	if(l==tl && r==tr)
	{
		t[v]^=xx;
	}
	else
	{
		ll tm=(tl+tr)/2;
		update(v*2,tl,tm,1,min(r,tm),xx);
		update(v*2+1,tm+1,tr,max(1LL,tm+1),r,xx);
	}
}

ll get(ll v,ll tl,ll tr,ll pos)
{
	if(tl==tr)
		return t[v];
	ll tm=(tl+tr)/2;
	if (pos <= tm)
        return t[v] ^ get(v*2, tl, tm, pos);
    else
        return t[v] ^ get(v*2+1, tm+1, tr, pos);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			ll num;
			cin>>num;
			if(i==j)
			{
				arr[i]=num;
			}
		}
	}
	build(arr,1LL,0LL,n-1);
	ll q;
	cin>>q;
	while(q--)
	{
		ll g,aa,bb,cc;
		cin>>g>>aa>>bb>>cc;
		update(1LL,0LL,n-1,aa-1,bb-1,cc);
	}
	ll ans=0;
	for(ll pp=0;pp<n;pp++)
	{
		ans+=get(1LL,0LL,n-1,pp);
	}
	cout<<ans;
    return 0;
}


//252908XL