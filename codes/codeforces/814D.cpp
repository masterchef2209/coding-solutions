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

ll n;

#define fi first
#define se second

ll f[1005][2][2];

ll x[1005];
ll y[1005];
ll r[1005];
ll par[1005];

vector< vector<ll> >adj(1005);

inline bool circle_contains(ll j,ll i)
{
	return (((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))<=(r[j]-r[i])*(r[j]-r[i]) );
}

void dfs(ll curr)
{
	ll g[2][2]={{0}};
	for(auto &nei:adj[curr])
	{
		dfs(nei);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				g[i][j]+=f[nei][i][j];
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			f[curr][i][j]=max(
				//u is added in 1st set
				g[i^1][j]+r[curr]*r[curr]*((i==0)?1:-1),//i==0 implies 1st set have odd elements now
				//u is added in 2nd set
				g[i][j^1]+r[curr]*r[curr]*((j==0)?1:-1)
			);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>r[i];
	}
	for(ll i=1;i<=n;i++)
	{
		par[i]=-1;
		for(ll j=1;j<=n;j++)
		{
				if(r[j]>r[i] && circle_contains(i,j))
				{
					if(par[i]==-1 || r[par[i]]>r[j])
					{
						par[i]=j;
					}
				}
		}
		if(par[i]!=-1)
		    adj[par[i]].eb(i);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
	    if(par[i]==-1)
	    {
		    dfs(i);
		    ans+=f[i][0][0];
	    }
	}
	cout<<fixed<<setprecision(8)<<(PI*(double)ans);
    return 0;
}