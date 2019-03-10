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

vector< vi > adj(310);
vi visited(310,0);
vi value(310);
vi ans(310);
vector< set<int> >components(310);

int yo=0;

void dfs(int i)
{
	visited[i]=1;
	components[yo].insert(i);
	for(auto &x:adj[i])
	{
		if(!visited[x])
			dfs(x);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>value[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char temp;
			cin>>temp;
			if(temp=='1')
			{
				adj[i].eb(j);
				adj[j].eb(i);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			yo++;
			dfs(i);
		}
	}
	for(auto &x:components)
	{
	    multiset<int>ss;
		for(auto &y:x)
		{
			ss.insert(value[y]);
		}
		auto it=ss.begin();
		for(auto &y:x)
		{
		    ans[y]=(*it);
		    it++;
		}
	}
	for(int i=1;i<=n;i++)
	{
	    cout<<ans[i]<<" ";
	}
    return 0;
}