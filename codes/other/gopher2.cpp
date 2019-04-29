#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

//not accepted

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

ll n,m,s,v;
ll nodes;
vector< pair<double,double> >posgop,poshol;

ll capacity[203][203];

vector< vector<ll> >adj(203);

ll bfs(ll s,ll t, vector<ll>&parent)
{
	for(ll i=1;i<=nodes;i++) parent[i]=-1;
	parent[s]=-2;
	queue< pair<ll,ll> >Q;
	Q.push({s,LLONG_MAX});
	while(!Q.empty())
	{
		ll curr=Q.front().fi;
		ll flow=Q.front().se;
		Q.pop();
		for(auto &next:adj[curr])
		{
			if(parent[next]==-1 && capacity[curr][next])
			{
				parent[next]=curr;
				ll new_flow=min(flow,capacity[curr][next]);
				if(next==t)
					return new_flow;
				Q.push({next,new_flow});
			}
		}
	}

return 0;
}

ll maxflow(ll s,ll t)
{
	ll flow=0;
	vector<ll>parent(nodes+1);
	ll new_flow;
	while((new_flow=bfs(s,t,parent) ) )
	{
		flow+=new_flow;
		ll curr=t;
		while(curr!=s)
		{
			ll prev=parent[curr];
			capacity[prev][curr]-=new_flow;
			capacity[curr][prev]+=new_flow;
			curr=prev;
		}
	}
return flow;
}

double dist(pair<double,double>&a,pair<double,double>&b)
{
    return sqrt(((a.fi-b.fi)*(a.fi-b.fi))+((a.se-b.se)*(a.se-b.se)) );
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(ll i=0;i<203;i++)
	{
		for(ll j=0;j<203;j++)
		{
			capacity[i][j]=0;
		}
	}
	cin>>n>>m>>s>>v;
	double d=s*v;
	for(ll u=0;u<n;u++)
	{
		double x,y;
		cin>>x>>y;
		posgop.eb(x,y);
	}
	for(ll u=0;u<m;u++)
	{
		double x,y;
		cin>>x>>y;
		poshol.eb(x,y);
	}
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			if(dist(posgop[i],poshol[j])<d)
			{
				capacity[i+1][n+j+1]=1;
				adj[i+1].eb(n+j+1);
				//cout<<i+1<<" "<<n+j+1<<endl;
			}
		}
	}
	nodes=n+m+2;
	ll s=n+m+2;
	ll t=n+m+1;
	for(ll i=0;i<n;i++)
	{
	   // cout<<s<<" "<<i+1<<endl;
		capacity[s][i+1]=1;
		adj[s].eb(i+1);
	}
	for(ll j=0;j<m;j++)
	{
	   // cout<<j+1+n<<" "<<t<<endl;
		capacity[j+1+n][t]=1;
		adj[j+1+n].eb(t);
	}
	cout<<(n-maxflow(s,t));
    return 0;
}