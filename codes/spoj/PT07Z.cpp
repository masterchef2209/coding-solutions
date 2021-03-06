#include <bits/stdc++.h>
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

vector< vi >adj(10005);
vi visited(10005);

int maxCount=INT_MIN;
int last;

void dfs(int node,int count)
{
	visited[node]=1;
	count++;
	for(auto &x:adj[node])
	{
		if(!visited[x])
		{
			if(count>=maxCount)
			{
				maxCount=count;
				last=x;
			}
			dfs(x,count);
		}
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
	for(int i=0;i<=n;i++)
	{
		visited[i]=0;
	}
	dfs(1,1);
	for(int i=0;i<=n;i++)
	{
		visited[i]=0;
	}
	maxCount=INT_MIN;
	dfs(last,1);
	cout<<maxCount-1<<endl;
    return 0;
}