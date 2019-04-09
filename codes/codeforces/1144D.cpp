#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
//using namespace __gnu_pbds;
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
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>arr;
	map<ll,ll>mm;
	ll biggie,bigval=-1,bigind;
	for(ll i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		arr.eb(temp);
		mm[temp]++;
		if(mm[temp]>bigval)
		{
			bigval=mm[temp];
			biggie=temp;
			bigind=i;
		}
	}
	vector< tuple<ll,ll,ll> >ans;
	for(ll i=bigind+1;i<arr.size();i++)
	{
		if(arr[i-1]==biggie && arr[i]==biggie)
			continue;
		else
		{
			if(arr[i]>biggie)
			{
				ans.eb(make_tuple(2,i-1,i));
				arr[i]=biggie;
			}
			else
			{
				ans.eb(make_tuple(1,i-1,i));
				arr[i]=biggie;
			}
		}
	}
	for(ll i=bigind-1;i>=0;i--)
	{
		if(arr[i+1]==biggie && arr[i]==biggie)
			continue;
		else
		{
			if(arr[i]>biggie)
			{
				ans.eb(make_tuple(2,i+1,i));
				arr[i]=biggie;
			}
			else
			{
				ans.eb(make_tuple(1,i+1,i));
				arr[i]=biggie;
			}
		}
	}
	cout<< ans.size() <<endl;
	for(auto &x:ans)
	{
		cout<< get<0>(x) <<" "<< get<2>(x)+1 <<" "<< get<1>(x)+1 <<endl;
	}
    return 0;
}