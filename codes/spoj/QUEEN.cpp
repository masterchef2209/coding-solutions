#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ppi pair<pii,int>
#define X first
#define Y second

int n,m;
int sx,sy,fx,fy;

char grid[1001][1001];
int done[1001][1001];
int dp[1001][1001];

int dx[8]={0,1,0,-1,-1,1,1,-1};
int dy[8]={1,0,-1,0,1,-1,1,-1};

inline bool ingrid(int i,int j){
    return (i >= 0 && j >= 0 && i < n && j < m );
}

void bfs()
{
	queue<pii>Q;
	Q.push(pii(sx,sy));
	while(!Q.empty())
	{
		pii x=Q.front();
		Q.pop();
		if(x.X==fx && x.Y==fy)
		{
			cout<<dp[x.X][x.Y]<<endl;
			return;
		}
		for(int i=0;i<8;i++)
		{
			int di=1,nx,ny; 
			while(1)
			{
				nx=x.X+dx[i]*di;
				ny=x.Y+dy[i]*di;
				if(ingrid(nx,ny) && grid[nx][ny]!='X' && !(done[nx][ny]&(1<<i)))
				{	
					if(!done[nx][ny])
						dp[nx][ny]=dp[x.X][x.Y]+1,Q.push(pii(nx,ny));
					done[nx][ny]|=(1<<i);
				}
				else
					break;
				di++;
			}
		}
	}
	cout<<-1<<endl;
return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				else if(grid[i][j]=='F')
				{
					fx=i;
					fy=j;
				}
				done[i][j]=0;
        dp[i][j]=-1;
			}
		}
		done[sx][sy]=255;
		dp[sx][sy]=0;
		bfs();
	}

return 0;
}