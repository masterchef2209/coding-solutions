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

int n,m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test=1;
	while(cin>>n)
	{
		vector< vector<int> >adj(110);
		vector<int>indegree(110,0);
		map<string,int>sti;
		map<int,string>its;
		for(int i=1;i<=n;i++)
		{
			string tmp;
			cin>>tmp;
			sti[tmp]=i;
			its[i]=tmp;
		}
		cin>>m;
		for(int u=0;u<m;u++)
		{
			string a,b;
			cin>>a>>b;
			adj[sti[a]].eb(sti[b]);
			indegree[sti[b]]++;
		}
	    priority_queue<int,vector<int>,greater<int> >Q;
		vector<int>ans;
		for(int i=1;i<=n;i++)
		{
			if(indegree[i]==0)
				Q.push(i);
		}
		while(!Q.empty())
		{
			int curr=Q.top();
			Q.pop();
			ans.eb(curr);
			for(auto &nei:adj[curr])
			{
				indegree[nei]--;
				if(indegree[nei]==0)
					Q.push(nei);
			}
		}
		cout<<"Case #"<<test<<": Dilbert should drink beverages in this order: ";
		for(int noo=0;noo<ans.size();noo++)
		{
			cout<<its[ans[noo]];
			if(noo!=(ans.size()-1))
				cout<<" ";
			else
				cout<<".\n\n";
		}
		test++;
	}
    return 0;
}