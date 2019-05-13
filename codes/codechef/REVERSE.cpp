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
#define int long long
//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
#define INF 1000000000
#define fi first
#define se second

vector< set<int> >adj(200005);
vector< set<int> >adjo(200005);
vector<int>dist(200005,INF);
vector<int>visited(200005,0);


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int u=0;u<m;u++)
	{
	    int a,b;
	    cin>>a>>b;
		adj[a].insert(b);
		adjo[b].insert(a);
	}
	deque<int>Q;
	Q.push_front(1);
	dist[1]=0;
	visited[1]=0;
	while(!Q.empty())
	{
		int curr=Q.front();
		Q.pop_front();
		if(visited[curr]++)continue;
		for(auto &nei:adj[curr])
		{
			if(dist[nei]>dist[curr])
			{
				dist[nei]=dist[curr];
				Q.push_front(nei);
			}
		}
		for(auto &nei:adjo[curr])
		{
			if(dist[nei]>(dist[curr]+1))
			{
				dist[nei]=dist[curr]+1;
				Q.push_back(nei);
			}
		}
	}
	if(dist[n]==INF)
		cout<<-1;
	else
		cout<<dist[n];
    return 0;
}