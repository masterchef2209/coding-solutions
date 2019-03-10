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

vector< vi >adj(110);
vi visited(110,0);

int count=0;

void dfs(int i)
{
	visited[i]=1;
	for(auto &x:adj[i])
	{
		if(!visited[x])
			dfs(x);
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
	if(n!=m)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"FHTAGN!"<<endl;
    return 0;
}