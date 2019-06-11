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

vector< vector<int> >adj(100005);
vector<int>visited(100005,-1);
stack<int>st;

int ans=0;

int flag=0;

void dfs(int curr)
{
	visited[curr]=1;
	for(auto &nei:adj[curr])
	{
		if(!visited[nei])
			dfs(nei);
	}
	if(flag==1)
		st.push(curr);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		ans=0;
		while(!st.empty())
		    st.pop();
		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
			visited[i]=0;
		}
		for(int u=0;u<m;u++)
		{
			int a,b;
			cin>>a>>b;
			adj[a].eb(b);
		}
		flag=1;
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
				dfs(i);
		}
		for(int i=0;i<=n;i++)
		{
			visited[i]=0;
		}
		flag=0;
		for(int i=1;i<=n;i++)
		{
			int a=st.top();
			st.pop();
			if(!visited[a])
			{
				dfs(a);
				ans++;
			}
		}
        cout<<ans<<endl;
	}
    return 0;
}