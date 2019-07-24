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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<ll>A(n),B(m);
	ll mm=-1;
	for(ll i=0;i<n;i++)
	{
		cin>>A[i];
		mm=max(mm,A[i]);
	}
	sort(A.rbegin(),A.rend());
	ll sum=0;
	for(ll j=0;j<m;j++)
	{
		cin>>B[j];
		sum+=B[j];
	}
	int flag=0;
	for(ll j=0;j<m;j++)
	{
		if(B[j]<mm)
		{
			cout<<-1;
			return 0;
		}
		if(B[j]==mm)
		{
			flag=1;
		}
	}
	ll ans=0;
	if(flag)
	{
		ans+=sum;
		for(ll k=1;k<n;k++)
		{
			ans+=(m*A[k]);
		}
	}
	else
	{
		ans+=sum;
		ans+=A[0];
		ans+=((m-1)*A[1]);
		for(ll k=2;k<n;k++)
		{
			ans+=(m*A[k]);
		}
	}
	cout<<ans;
    return 0;
}


//252908XL