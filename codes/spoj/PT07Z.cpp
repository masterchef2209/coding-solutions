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
vi height(10005,0);

int get_height(int i,int p)
{
	if(i>1 && adj[i].size()==1)
	{
		height[i]=0;
		return 1;
	}
	else
	{
		int temp=-1;
		for(auto& x:adj[i])
		{
		    if(x!=p)
			    temp=max(temp,get_height(x,i));
		}
		height[i]=temp;
		return temp+1;
	}
}

int func(int i)
{
	int h=get_height(i,-1);
	vector<int>heights;
	for(auto &x:adj[i])
	{
		heights.eb(height[x]);
	}
	if(heights.size()==1)
	    return 1+heights[0];
	sort(heights.rbegin(),heights.rend());
	return 1+heights[0]+heights[1];
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
	cout<<func(1)<<endl;
    return 0;
}