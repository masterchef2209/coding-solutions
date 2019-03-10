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
vi color(100005);

int status=0;

void dfs(int i,int col)
{
	visited[i]=1;
	if(status==1 || color[i]!=col)
	{
		status=1;
		return;
	}
	for(auto &x: adj[i])
	{
		if(status==1)
			return;
		if(!visited[x])
			dfs(x,col);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>color[i];
	}
	vi root1;
	for(int i=1;i<=n;i++)
	{
		for(auto &x:adj[i])
		{
			if(color[i]!=color[x])
			{
			    root1.eb(i);
			    root1.eb(x);
			    goto label;
			}
		}
	}
	label:;
	if(root1.empty())
	{
	    cout<<"YES"<<endl;
	    cout<<1<<endl;
	    return 0;
	}
	for(auto &z:root1)
	{
		for(int i=1;i<=n;i++)
		{
			visited[i]=0;
		}
		status=0;
		visited[z]=1;
		for(auto &y: adj[z])
		{
			dfs(y,color[y]);
			if(status)
			{
				break;
			}
		}
		if(status==0)
		{
			cout<<"YES"<<endl;
			cout<<z<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
    return 0;
}