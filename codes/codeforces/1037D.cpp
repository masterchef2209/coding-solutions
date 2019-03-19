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

vector< vi >adj(200005);
vi visited(200005,0);
vi given;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	for(int u=0;u<n;u++)
	{
		int temp;
		cin>>temp;
		given.eb(temp);
	}
	if(given[0]!=1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	queue< int >Q;
	Q.push(1);
	visited[1]=1;
	int yo=1;
	while(!Q.empty())
	{
		int up=Q.front();
		Q.pop();
		multiset<int>haha,haha1;
		for(auto &x:adj[up])
		{
			if(!visited[x])
			{
				haha.insert(x);
			//	cout<<x<<"_"<<given[yo]<<" ";
				visited[x]=1;
				Q.push(given[yo]);
				haha1.insert(given[yo++]);
			}
		}
	//	cout<<endl;
		if(haha!=haha1)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
    return 0;
}