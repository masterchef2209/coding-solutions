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

int yo=0;

int ans=-1;

vector< vi >adj(210);
map<string,int>mm;

void dfs(int i,int temp)
{
	if(adj[i].empty())
	{
		ans=max(ans,temp);
	}
	for(auto &x:adj[i])
	{
		dfs(x,temp+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string c,d,a(""),x,b("");
		cin>>c>>x>>d;
		for(int i=0;i<c.size();i++)
		{
			a+=tolower(c[i]);
		}
		for(int i=0;i<d.size();i++)
		{
			b+=tolower(d[i]);
		}
		if(mm.find(b)==mm.end())
		{
			yo++;
			mm[b]=yo;
		}
		if(mm.find(a)==mm.end())
		{
			yo++;
			mm[a]=yo;
		}
		adj[mm[b]].eb(mm[a]);
	}
	dfs(1,1);
	cout<<ans<<endl;
    return 0;
}