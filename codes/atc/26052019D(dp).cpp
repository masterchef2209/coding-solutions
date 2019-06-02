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

vector<int>arr(55);
int dp[55][55][105];

int calculateanswer(int i,int j,int k)
{
    if(k<0)
        return (-1e9);
    if(i>j || k==0)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    int ans=0;
    ans=max(ans,arr[i]+calculateanswer(i+1,j,k-1));
    ans=max(ans,arr[j]+calculateanswer(i,j-1,k-1));
    ans=max(ans,calculateanswer(i+1,j,k-2));
    ans=max(ans,calculateanswer(i,j-1,k-2));
    return dp[i][j][k]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	memset(dp , -1 , sizeof(dp)) ;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<calculateanswer(0,n-1,k);
    return 0;
}