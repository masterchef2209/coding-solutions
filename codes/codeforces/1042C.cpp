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

#define int long long

signed main()
{
	int n;
	scanf("%lld",&n);
	vector<ll>arr(n+1);
	vector<ll>zero1;
	vector<ll>nonzero1;
	ll son=LLONG_MIN;
	int sonid=-1,zero=-1;
	ll count1=0;

	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
		if(arr[i]<0)
			count1++;
		if(arr[i]<0 && arr[i]>son)
		{
			son=arr[i];
			sonid=i;
		}
		if(arr[i]==0)
		{
			zero1.eb(i);
			zero=i;
		}
		else
		{
			nonzero1.eb(i);
		}
	}
		if(count1&1)
		{
			zero1.eb(sonid);
			sort(zero1.begin(),zero1.end());
			zero=max(zero,sonid);
			nonzero1.erase(find(nonzero1.begin(),nonzero1.end(),sonid));
		}

	    if(zero1.size()>=2)
	    {
	        for(int i=0;i<zero1.size()-1;i++)
		    {
			    printf("1 %lld %lld\n",zero1[i],zero1[i+1]);
		    }
	    }
	    if( ((ll)zero1.size())!=n && zero!=-1)
			printf("2 %lld\n",zero);
		if(nonzero1.size()>=2)
		{
		    for(int i=0;i<nonzero1.size()-1;i++)
		    {
			    printf("1 %lld %lld\n",nonzero1[i],nonzero1[i+1]);
		    }
		}

    return 0;
}