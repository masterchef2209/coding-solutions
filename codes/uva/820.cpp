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
ll s,t,c;
ll capacity[102][102];

vector< vector<ll> >adj(102);

ll bfs(ll s,ll t, vector<ll>&parent)
{
	for(ll i=0;i<=n;i++)
	{
		parent[i]=-1;
	}
	parent[s]=-2;
	queue< pair<ll,ll> >Q;
	Q.push({s,(LLONG_MAX)});
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
				{
					return new_flow;
				}
				Q.push({next,new_flow});
			}
		}
	}
return 0;
}

ll maxflow(ll s,ll t)
{
	ll flow=0;
	vector<ll>parent(n+1);
	ll new_flow;
	while((new_flow=bfs(s,t,parent)) )
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	ll test=1;
	while(n!=0)
	{
		cin>>s>>t>>c;
// 		if(test!=1)
// 		    cout<<"\n";
		cout<<"Network "<<test++<<"\n";
		for(ll i=0;i<=n;i++)
		{
			adj[i].clear();
			for(ll j=0;j<=n;j++)
			{
				capacity[i][j]=0;
			}
		}
		for(ll i=0;i<c;i++)
		{
			ll a,b,cap;
			cin>>a>>b>>cap;
            adj[a].eb(b);
            adj[b].eb(a);
            capacity[a][b]+=cap;
            capacity[b][a]+=cap;
		}
		cout<< "The bandwidth is "<<maxflow(s,t)<<".\n\n";
		cin>>n;
	}
    return 0;
}