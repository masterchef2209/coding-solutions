#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(n==1)
	{
		cout<<"3";
		return 0;
	}
	vector<ll>ans;
	if(arr[0]==arr[1])	ans.eb(3);
	else if(arr[0]>arr[1])	ans.eb(5);
	else if(arr[1]>arr[0])	ans.eb(1);
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1] && ans[i-1]==5){ cout<<-1;return 0;}
		if(arr[i]<arr[i-1] && ans[i-1]==1){ cout<<-1;return 0;}
		ll curr;
		if(arr[i]>arr[i-1])
		{
			curr=ans[i-1]+1;
			if(i<n-1)
			{
				if(arr[i+1]<arr[i])	curr=5;
			}
		}
		else if(arr[i]<arr[i-1])
		{
			curr=ans[i-1]-1;
			if(i<n-1)
			{
				if(arr[i+1]>arr[i])	curr=1;
			}
		}
		else if(arr[i]==arr[i-1])
		{
			curr=(ans[i-1]==3)?2:3;
			if(i<n-1)
			{
				if(arr[i+1]>arr[i]){	curr=((ans[i-1]==1)?2:1);	}
				if(arr[i+1]<arr[i]){	curr=((ans[i-1]==5)?4:5);	}
			}
		} 
		ans.eb(curr);
	}
	for(ll i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}