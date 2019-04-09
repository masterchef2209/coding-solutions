#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
//using namespace __gnu_pbds;
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
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

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

vector< ii >edges;
vector< vi >adj(200005);
vi color(200005,0);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int u=0;u<m;u++)
	{
		int a,b;
		cin>>a>>b;
		edges.eb(mp(a,b));
		adj[a].eb(b);
		adj[b].eb(a);
	}
	queue<int>Q;
	Q.push(1);
	color[1]=1;
	while(!Q.empty())
	{
		int curr=Q.front();
		Q.pop();
		for(auto &nei:adj[curr])
		{
			if(color[curr]==color[nei])
			{
				cout<<"NO"<<endl;
				return 0;
			}
			if(color[nei]==0)
			{
				if(color[curr]==1)
					color[nei]=2;
				else if(color[curr]==2)
					color[nei]=1;
				Q.push(nei);
			}
		}
	}
	cout<<"YES"<<endl;
	for(auto &e:edges)
	{
		if(color[e.fi]==1 && color[e.se]==2)
			cout<<1;
		else if(color[e.fi]==2 && color[e.se]==1)
			cout<<0;
	}
    return 0;
}