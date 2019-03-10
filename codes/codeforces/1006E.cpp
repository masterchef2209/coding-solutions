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
vi ssize(200005);
int yo=0;
vi inorder(200005);
vi haha(200005);

void dfs(int i)
{
	haha[i]=yo;
	inorder[yo++]=i;
	for(auto &x: adj[i])
	{
		dfs(x);
	}
	ssize[i]=yo;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	for(int u=2;u<=n;u++)
	{
		int p;
		cin>>p;
		adj[p].insert(u);
	}
	dfs(1);
	for(int u=0;u<q;u++)
	{
		int node,index;
		cin>>node>>index;
		if((haha[node]+index-1)>=n || (index>(ssize[node]-haha[node]) )  )
			cout<<-1<<endl;
		else
			cout<<inorder[haha[node]+index-1]<<endl;
	}
    return 0;
}