#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

vector< vector<int> >adj(1000006);
vector< int >visited(1000006);
vector< int >low(1000006);
vector< int >ti(1000006);

int n,timer;

vector< pair<int,int> >ans;

void dfs(int i,int parent=-1)
{
	visited[i]=1;
	low[i]=ti[i]=timer++;
	for(auto &nei:adj[i])
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
			if(low[nei]>ti[i])
			{
				int x=(nei<i)?nei:i;
				int y=(i>nei)?i:nei;
				ans.eb(mp(x,y));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	while(cin>>n)
	{
		ans.clear();
		timer=0;
		for(int i=0;i<n;i++)
		{
			visited[i]=0;
			adj[i].clear();
			low.assign(n,-1);
			ti.assign(n,-1);
		}
		for(int i=0;i<n;i++)
		{
			int index;
			cin>>index;
			char w1,w2;
			cin>>w1;
			int m;
			cin>>m;
			cin>>w2;
			for(int i=0;i<m;i++)
			{
				int x;
				cin>>x;
				adj[index].eb(x);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
				dfs(i,-1);
		}
		cout<<ans.size()<<" critical links"<<endl;
		sort(ans.begin(),ans.end());
		for(auto &x:ans)
		{
			cout<<x.first<<" - "<<x.second<<endl;
		}
		cout<<endl;
	}
    return 0;
}