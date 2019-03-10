#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define f first
#define s second

vector< vi >adj(100005);
vi visited(100005,0);

int c=1;

void dfs(int i,int p)
{
	visited[i]=1;
	for(auto &x:adj[i])
	{
		if(x==p)
			continue;
		if(!visited[x])
			dfs(x,i);
		else
		{
			c=0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		c=1;
		if(!visited[i])
		{
			dfs(i,-1);
			ans+=c;
		}
	}
	cout<<ans<<endl;
    return 0;
}