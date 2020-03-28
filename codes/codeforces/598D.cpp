		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)

//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};

#define fi first
#define se second

#define SSIZE 1005

ll n,m,k;

char grid[SSIZE][SSIZE];
ll visited[SSIZE][SSIZE];

map< pair<ll,ll>,ll>mm;
vector< pair<ll,ll>  >cmp;

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};

void bfs(ll x,ll y)
{
	cmp.clear();
	queue< pair<ll,ll> >Q;
	Q.push(mp(x,y));
	ll ret=0;
	cmp.eb(x,y);
	visited[x][y]=1;
	while(!Q.empty())
	{
		auto curr=Q.front();
		Q.pop();
		for(ll k=0;k<4;k++)
		{
			pair<ll,ll>nei=mp(curr.fi+dx[k],curr.se+dy[k]);
			if(!visited[nei.fi][nei.se] && grid[nei.fi][nei.se]=='.')
			{
			    visited[nei.fi][nei.se]=1;
				cmp.eb(nei);
				Q.push(nei);
			}
			if(grid[nei.fi][nei.se]=='*')
				ret++;
		}
	}
	for(auto &lol:cmp)
	{
		mm[lol]=ret;
	}
	cmp.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(ll i=0;i<SSIZE;i++)
	for(ll j=0;j<SSIZE;j++)
		grid[i][j]='0';
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(ll u=0;u<k;u++)
	{
		ll x,y;
		cin>>x>>y;
		if(visited[x][y]==1)
		{
			cout<<mm[mp(x,y)]<<endl;
		}
		else
		{
			bfs(x,y);
			cout<<mm[mp(x,y)]<<endl;
		}
	}
    return 0;
}


//252908XL