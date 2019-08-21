		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef int ll;

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

#define SIZE 1000*1000
#define BITSIZE 30

ll l[SIZE],r[SIZE],q[SIZE];

ll temp[SIZE];

ll ans[SIZE];
ll t[4*SIZE];

inline void build(int v, int l, int r) {
 	if (l+1== r) {
 	 	t[v] = ans[l];
 	 	return;
 	}
 
 	int mid = (l + r) >> 1;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid, r);
 
	t[v] = t[v * 2] & t[v * 2 + 1];
}
 
inline int query(int v, int l, int r, int L, int R) {
 	if (l == L && r == R) {
 	 	return t[v];
 	}
 	int mid = (L + R) >> 1;
 	int ans = (1ll << BITSIZE) - 1;
 
 	if (l < mid) 
 		ans &= query(v * 2, l, std::min(r, mid), L, mid);
 	if (mid < r) 
 		ans &= query(v * 2 + 1, std::max(l, mid), r, mid, R);
 
 	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(ll u=0;u<m;u++)
	{
		cin>>l[u]>>r[u]>>q[u];
		l[u]--;
	}
	for(ll bit=0;bit<=BITSIZE;bit++)
	{
		for(ll i=0;i<SIZE;i++)
			temp[i]=0;
		for(ll j=0;j<m;j++)
		{
			if((q[j]>>bit)&1)
			{
				temp[l[j]]++;
				temp[r[j]]--;
			}
		}
		for(ll i=0;i<n;i++)
		{
			if(i>0)
				temp[i]+=temp[i-1];
			if(temp[i]>0)
			{
				ans[i]|=(1LL<<bit);
			}
		}
	}
	
	build(1,0,n);
	for(ll i=0;i<m;i++)
	{
		if(query(1, l[i], r[i], 0, n)!=q[i])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	for(ll i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}


//252908XL