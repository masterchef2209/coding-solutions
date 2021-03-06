#include <bits/stdc++.h>
//Flood fill baby
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
#define pt pair<int,int>
int n,m;

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

int grid[110][110];
bool visited[110][110];

priority_queue< pair<int,pt > ,vector< pair<int,pt > >,greater< pair<int,pt > > > pq;

inline bool ingrid(pt x)
{
	return (x.fi>=1 && x.fi<=n && x.se>=1 && x.se<=m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll ans=0;
		cin>>n>>m;
		pq=priority_queue< pair<int,pt > ,vector< pair<int,pt > >,greater< pair<int,pt > > >();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				visited[i][j]=false;
				cin>>grid[i][j];
				if(i==1 || j==1 || i==n || j==m)
				{
					pq.push(mp(grid[i][j],mp(i,j)));
				}
			}
		}
		while(!pq.empty())
		{
			pt point=pq.top().se;
			int height=grid[point.fi][point.se];
			pq.pop();
			if(visited[point.fi][point.se])
				continue;
		    //cout<<point.fi<<" "<<point.se<<endl;
		    
			queue< pt >Q;
			Q.push( point );
			visited[point.fi][point.se]=true;
 			while(!Q.empty())
			{
				pt po=Q.front();
				Q.pop();
				for(int u=0;u<4;u++)
				{
					pt npo=mp(po.fi+dr[u],po.se+dc[u]);
					if(ingrid(npo) && !visited[npo.fi][npo.se])
					{
						int nheight=grid[npo.fi][npo.se];
						if(nheight>height)
						{
							pq.push(mp(nheight,npo));
						}
						else
						{
							ans+=(height-nheight);
						//	grid[npo.fi][npo.se]=height;
							visited[npo.fi][npo.se]=true;
							Q.push(npo);
						}
					}
				}
 			}
 			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
    return 0;
}