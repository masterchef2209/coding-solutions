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

#define INF (1<<29)

char grid[1005][1005];
ll dist[1005][1005];
ll visited[1005][1005];

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};

ll r,c;

inline bool ingrid(ll a,ll b)
{
    return (a>=1 && b>=1 && a<=r && b<=c);
}

void bfs(ll sx,ll sy)
{
	visited[sx][sy]=1;
	queue< pair<ll,ll> >Q;
	Q.push(mp(sx,sy));
	while(!Q.empty())
	{
		pair<ll,ll>curr=Q.front();
		Q.pop();
		for(int i=0;i<4;i++)
		{
			 pair<ll,ll>nei=mp(curr.fi+dx[i],curr.se+dy[i]);
			 if(ingrid(nei.fi,nei.se) && visited[nei.fi][nei.se]==0 && grid[nei.fi][nei.se]!='T')
			 {
			 	visited[nei.fi][nei.se]=1;
			 	dist[nei.fi][nei.se]=dist[curr.fi][curr.se]+1;
			 	Q.push(nei);
			 }
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>r>>c;
	ll sx,sy,ex,ey;
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++)
		{
			dist[i][j]=INF;
			visited[i][j]=0;
			cin>>grid[i][j];
			if(grid[i][j]=='E')
			{
				sx=i;
				sy=j;
				dist[i][j]=0;
			}
			if(grid[i][j]=='S')
			{
				ex=i;
				ey=j;
			}
		}
	}
	bfs(sx,sy);
// 	for(ll i=1;i<=r;i++)
//     {
//         for(ll j=1;j<=c;j++)
//         {
//             cout<<dist[i][j]<<" ";
//         }
//         cout<<endl;
//     }
	ll val=dist[ex][ey];
	ll ans=0;
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++)
		{
			if((grid[i][j]>='1')&&(grid[i][j]<='9'))
			{
				ll val1=grid[i][j]-'0';
				if(dist[i][j]<=val)
					ans+=val1;
			}
		}
	}
	cout<<ans;
    return 0;
}