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

vector< vector<ll> >adj(300);
vector< int >visited(300,0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n)
	{
		if(n==0)	break;
		for(int i=1;i<=n;i++)
		{
			visited[i]=0;
			adj[i].clear();
		}
		ll m;
		cin>>m;
		for(ll u=0;u<m;u++)
		{
			ll a,b;
			cin>>a>>b;
			adj[a+1].eb(b+1);
			adj[b+1].eb(a+1);
		}
		queue<ll>Q;
		Q.push(1);
		visited[1]=1;
		while(!Q.empty())
		{
			ll curr=Q.front();
			Q.pop();
			for(auto &nei:adj[curr])
			{
				if(!visited[nei])
				{
					if(visited[curr]==1)
					{
						visited[nei]=2;
					}
					else if(visited[curr]==2)
					{
						visited[nei]=1;
					}
					Q.push(nei);
				}
				else
				{
					if(visited[nei]==visited[curr])
					{
						cout<<"NOT BICOLORABLE.\n";
						goto out;
					}
				}
			}
		}
		cout<<"BICOLORABLE.\n";
		out:;
	}
    return 0;
}