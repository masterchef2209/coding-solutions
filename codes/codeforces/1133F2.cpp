#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
//not accepted
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

vector< vi >adj(200005);
vi visited(200005,0);
vi degree(200005,0);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m,d;
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
		degree[a]++;
		degree[b]++;
	}
	if(d>degree[1])
	{
		cout<<"NO"<<endl;
		return 0;
	}
	visited[1]=1;
	queue<int>Q;
	Q.push(1);
	set< pair<int,int> >ss;
	while(!Q.empty())
	{
		int temp=Q.front();
		Q.pop();
		for(auto &x:adj[temp])
		{
			if(!visited[x])
			{
				visited[x]=1;
				ss.insert(mp(temp,x));
				Q.push(x);
			}
			if(temp==1)
			{
				d--;
				if(d==0)
				{
					break;
				}
			}
		}
	}
	if(ss.size()!=n-1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		for(auto &y:ss)
		{
			cout<<y.first<<" "<<y.second<<endl;
		}
	}
    return 0;
}