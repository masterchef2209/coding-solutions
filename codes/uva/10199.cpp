#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
//not accepted
vector< vector<int> >adj(110);
vector< int >visited(110);
vector< int >low(110);
vector< int >ti(110);
int timer=0;

set<int>ans;

void dfs(int i,int parent)
{
	visited[i]=1;
	low[i]=ti[i]=timer++;
	int children=0;
	for(auto &nei: adj[i])
	{
		if(nei==parent)
			continue;
		if(visited[nei])
		{
			low[i]=min(low[i],ti[nei]);
		}
		else
		{
			dfs(nei,i);
			low[i]=min(low[i],low[nei]);
			if(low[nei]>=ti[i] && parent!=-1)
			{
				ans.insert(i);
			}
			children++;
		}
	}
	if(parent==-1 && children>1)
	{
		ans.insert(i);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n;
	int t=0;
	while(1)
	{
	    ans.clear();
		t++;
		cin>>n;
		if(n==0)
			break;
		timer=0;
		for(int i=0;i<=n;i++)
		{
			visited[i]=0;
			adj[i].clear();
			low[i]=-1;
			ti[i]=-1;
		}
		if(t>1)
		    cout<<endl;
		map<string,int>mm;
		map<int,string>mm1;
		for(int i=0;i<n;i++)
		{
			string temp;
			cin>>temp;
			mm[temp]=i+1;
			mm1[i+1]=temp;
		}
		int r;
		cin>>r;
		for(int i=0;i<r;i++)
		{
			string a,b;
			cin>>a>>b;
			int s=mm[a];
			int d=mm[b];
			adj[s].eb(d);
			adj[d].eb(s);
		}
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
				dfs(i,-1);
		}
		cout<<"City map #"<<t<<": "<<ans.size()<<" camera(s) found"<<endl;
		set<string>out;
		for(auto &x:ans)
		{
			out.insert(mm1[x]);
		}
		for(auto &y:out)
		{
		    cout<<y<<endl;
		}
	}
    return 0;
}