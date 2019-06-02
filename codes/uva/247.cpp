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

ll timer=0;

vector< vector<ll> >adj(30);
vector<ll>id(30,-1);
vector<ll>low(30,-1);
vector<ll>onstack(30);
stack<ll>st;

map<int,string>its;
map<string,int>sti;

void dfs(int curr)
{
	id[curr]=low[curr]=timer++;
	onstack[curr]=1;
	st.push(curr);

	for(auto &nei:adj[curr] )
	{
		if(id[nei]==-1)
			dfs(nei);
		if(onstack[nei])
			low[curr]=min(low[curr],low[nei]);
	}

	if(id[curr]==low[curr])
	{
		while(!st.empty())
		{
			ll pp=st.top();
			st.pop();
			onstack[pp]=0;
			low[pp]=id[curr];
			cout<<its[pp];
			if(pp!=curr)
			    cout<<", ";
			if(pp==curr)
				break;
		}
		cout<<endl;
	}
}

ll test=1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)	break;
		if(test!=1)
			cout<<endl;
		cout<<"Calling circles for data set "<<test++<<":\n";

		timer=0;

		its.clear();
		sti.clear();

		for(int i=1;i<=n;i++)
		{
			adj[i].clear();
			id[i]=low[i]=-1;
			onstack[i]=0;
		}

		int assigned=1;
		for(int i=1;i<=m;i++)
		{
			string a,b;
			cin>>a>>b;
			if(sti.find(a)==sti.end())
			{
				its[assigned]=a;
				sti[a]=assigned++;
			}
			if(sti.find(b)==sti.end())
			{
				its[assigned]=b;
				sti[b]=assigned++;
			}
			adj[sti[a]].eb(sti[b]);
		}
		for(int i=1;i<=n;i++)
		{
			if(id[i]==-1)
			{
				dfs(i);
			}
		}
	}

    return 0;
}