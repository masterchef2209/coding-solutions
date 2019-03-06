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
vector< int >ti(1000006),low(1000006);
int timer=0;

void dfs(int i,int parent)
{
	visited[i]=1;
	ti[i]=low[i]=timer++;
	for(auto &nei: adj[i])
	{
		if(nei==parent)
			continue;
		if(visited[nei]==0)
		{
		    cout<<i<<" "<<nei<<endl;
			dfs(nei,i);
			low[i]=min(low[i],low[nei]);
			if(low[nei]>ti[i])
			{
				cout<<nei<<" "<<i<<endl;
			}
		}
		if(visited[nei]==1)
		{
			low[i]=min(low[i],ti[nei]);
			cout<<i<<" "<<nei<<endl;
		}
	}
	visited[i]=2;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int n,m;
	int t=0;
	while(cin>>n>>m)
	{
		t++;
		if(n==0 && m==0)
			break;
		timer=0;
		for(int i=0;i<=n;i++)
		{
			visited[i]=0;
			adj[i].clear();
			ti[i]=-1;
			low[i]=-1;
		}
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			adj[a].eb(b);
			adj[b].eb(a);
		}
		cout<<t<<endl<<endl;
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
				dfs(i,-1);
		}
		cout<<"#"<<endl;
	}
    return 0;
}