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

#define N 100005
#define int long long
int n,m;

int arrival[N], departure[N], vis[N], parent[N];
vector<pair<int, int> > g[N];

vector< set<int> >timedelay(N);

void dijkstra(int source, int destination)
{
	for(int i=1;i<=n;i++)
	{
		arrival[i]=1e18;
		departure[i]=1e18;
		vis[i]=0;
	}
	arrival[source]=0;
	set<pair<int, int> > s;
	s.insert({arrival[source], source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		departure[x.second]=arrival[x.second];
		while(timedelay[x.second].find(departure[x.second])!=timedelay[x.second].end())
		    departure[x.second]++;
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first]=departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].eb(mp(b,c));
		g[b].eb(mp(a,c));
	}
	for(int i=1;i<=n;i++)
	{
	    int fuck;
	    cin>>fuck;
	    while(fuck--)
	    {
	        int tmp;
	        cin>>tmp;
	        timedelay[i].insert(tmp);
	    }
	}
	dijkstra(1,n);
	if(!vis[n])
	{
		cout<<"-1";
		return 0;
	}
	dijkstra(1,n);
	cout<<arrival[n]<<endl;
    return 0;
}