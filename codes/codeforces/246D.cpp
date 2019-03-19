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
vector< set<int> >freq(100005);

void bfs(int i)
{
	queue<int>Q;
	Q.push(i);
	visited[i]=1;
	while(!Q.empty())
	{
		int y=Q.front();
		Q.pop();
		for(auto &x:adj[y])
		{
			freq[color[y] ].insert(color[x]);
			if(!visited[x])
			{
				visited[x]=1;
				Q.push(x);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	set<int>big;
	for(int i=1;i<=n;i++)
	{
		cin>>color[i];
		big.insert(color[i]);
	}
	for(int u=0;u<m;u++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			bfs(i);
	}
	int ans=-1;
	int temp=-1;
	for(auto &i:big)
	{
		freq[i].erase(i);
// 		cout<<freq[i].size()<<"_";
// 		for(auto &l: freq[i])
// 		{
// 		    cout<<l<<" ";
// 		}
// 		cout<<endl;
		if(  ((int)freq[i].size() ) > temp )
		{
			temp=freq[i].size();
			ans=i;
		}
	}
	cout<<ans<<endl;
	//cout<<temp<<endl;
    return 0;
}