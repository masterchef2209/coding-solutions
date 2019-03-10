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

vector< set<int> >adj(200005);
vi visited(200005,0);
vi color(200005);

priority_queue<int>pq;
map<int,int>mm;

void dfs(int i)
{
	visited[i]=1;
	mm[color[i]]++;
	pq.push(mm[color[i]]);
	for(auto &x:adj[i])
	{
		if(!visited[x])
			dfs(x);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>color[i];
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			pq=priority_queue<int>();
			mm.clear();
			dfs(i);
			ans-=(pq.top());
		}
	}
	cout<<ans<<endl;
    return 0;
}