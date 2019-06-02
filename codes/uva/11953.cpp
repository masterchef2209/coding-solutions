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

ll n;

char grid[101][101];
int visited[101][101];

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};

inline bool ingrid(ll a,ll b)
{
    return (a>=1 && a<=n && b>=1 && b<=n);
}

ll bfs(ll sx,ll sy)
{
	queue< pair<ll,ll> >Q;
	visited[sx][sy]=1;
	Q.push(mp(sx,sy));
	ll at=0,x=0;
	while(!Q.empty())
	{
		pair<ll,ll> curr=Q.front();
		if(grid[curr.fi][curr.se]=='@')
			at++;
		else if(grid[curr.fi][curr.se]=='x')
			x++;
		Q.pop();
		for(int i=0;i<4;i++)
		{
			pair<ll,ll>nei=mp(curr.fi+dx[i],curr.se+dy[i]);
			if(ingrid(nei.fi,nei.se) && visited[nei.fi][nei.se]==0)
			{
				visited[nei.fi][nei.se]=1;
				Q.push(nei);
			}
		}
	}
	if(x==0)
		return 0;
	else
		return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	for(ll test=1;test<=t;test++)
	{
		
		cin>>n;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
			{
				visited[i][j]=0;
				cin>>grid[i][j];
				if(grid[i][j]=='.')
					visited[i][j]=1;
			}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(visited[i][j]==0)
					ans+=bfs(i,j);
			}
		}
		cout<<"Case "<<test<<": "<<ans<<endl;
	}
    return 0;
}