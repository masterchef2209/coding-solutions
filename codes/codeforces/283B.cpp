		/*Read the problem carefully before starting to work on it*/
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

vector<ll>arr(200005);

ll dp[200005][2];
int n;
int alarm=0;

void dfs(int pos,int dir)
{
	if(pos<=0 || pos>n)
	{
		alarm=0;
		return;
	}
	if(pos==1)
	{
		alarm=1;
		return;
	}
	if(dp[pos][dir]>0)
	{
		alarm=0;
		return;
	}
	if(dp[pos][dir]==-1 || dp[pos][dir]==-2)
	{
		alarm=1;
		return;
	}
	if(dir==0)
	{
	    dp[pos][dir]=-2;
		dfs(pos-arr[pos],1-dir);
	}
	else if(dir==1)
	{
	    dp[pos][dir]=-2;
		dfs(pos+arr[pos],1-dir);
	}
	if(alarm==0)
	{
		dp[pos][dir]=arr[pos];
		if(dir==0)
		{
			if(pos-arr[pos]>1)
			{
				dp[pos][dir]+=dp[pos-arr[pos]][1-dir];
			}
		}
		else
		{
			if(pos+arr[pos]<=n)
			{
				dp[pos][dir]+=dp[pos+arr[pos]][1-dir];
			}
		}
	}
	else
	{
		dp[pos][dir]=-1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,0,sizeof(dp));
	
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>arr[i];
	}
//	0 means backward 1 means forward
	for(int i=2;i<=n;i++)
	{
		if(dp[i][0]==0)
		{
			alarm=0;
			dfs(i,0);
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(dp[i][0]==-1)
			cout<<-1<<endl;
		else
			cout<<dp[i][0]+(i-1)<<endl;
	}
    return 0;
}