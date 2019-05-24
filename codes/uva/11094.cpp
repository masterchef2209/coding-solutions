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
ll n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

ll grid[21][21];
char mp[21][21];
ll bfs(ll a,ll b)
{
	queue< pair<ll,ll> >Q;
	Q.push(mp(a,b));
	ll ret=0;
	grid[a][b]=1;
	while(!Q.empty())
	{
		pair<ll,ll> curr=Q.front();
		ret++;
		Q.pop();
		for(int i=0;i<4;i++)
		{
			ll xx=curr.fi+dx[i];
			if(xx==-1)
				continue;
			if(xx==n)
				continue;
			ll yy=curr.se+dy[i];
			if(yy==-1)
				yy=m-1;
			if(yy==m)
				yy=0;
			if(grid[xx][yy]==0)
			{
				pair<ll,ll>nei=mp(xx,yy);
				grid[xx][yy]=1;
				Q.push(nei);
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n>>m)
	{
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>mp[i][j];
		}
	}
	char zero;
	ll kx,ky;
	cin>>kx>>ky;
	zero=mp[kx][ky];
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			if(mp[i][j]==zero)
				grid[i][j]=0;
			else
				grid[i][j]=1;
		}
	}
	bfs(kx,ky);
	ll ans=0;
//	cout<<zero<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==0)
				ans=max(ans,bfs(i,j));
		}
	}
	cout<<ans<<endl;
	}
    return 0;
}