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
int dp[100005]={0};

multiset<int>nodes;
vector<int>ans;

void dfs(int i,int p)
{
	dp[i]=0;
	if(nodes.find(i)!=nodes.end())
		dp[i]+=1;
	for(auto &x:adj[i])
	{
		if(x==p)
			continue;
		dfs(x,i);
		dp[i]+=dp[x];
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int u=0;u<n-1;u++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].eb(b);
		adj[b].eb(a);
		if(c==2)
		{
			nodes.insert(a);
			nodes.insert(b);
		}
	}
	dfs(1,-1);
	for(auto &x:nodes)
	{
		if(dp[x]==1)
		{
			ans.eb(x);
		}
	}
	cout<<ans.size()<<endl;
	for(auto &y:ans)
	{
		cout<<y<<" ";
	}
    return 0;
}