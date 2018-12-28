#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ppi pair<pii,int>
//not accepted
char grid[21][21];
int dp[21][21][15];
int dirty=0;
int endgame;
int dr[4]={0,1,-1,0};
int dc[4]={1,0,0,-1};
int w,h;
vector<pii>bag;

inline bool ingrid(pii&o)
{
	return (o.first<h && o.first>=0 && o.second<w && o.second>=0);
}


int bfs(pii s)
{
	queue<ppi>Q;
	Q.push(ppi(s,0));
	dp[s.first][s.second][0]=0;
	while(!Q.empty())
	{
		pii x=Q.front().first;
		int mask=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++)
		{
			pii y=make_pair(x.first+dr[i],x.second+dc[i]);
			if(ingrid(y) && grid[y.first][y.second]!='x')
			{
        if(dp[y.first][y.second][mask]==-1)
        {
					if(grid[y.first][y.second]=='.' || grid[y.first][y.second]=='o')
					{
						Q.push(ppi(y,mask));
						dp[y.first][y.second][mask]=dp[x.first][x.second][mask]+1;
            //cout<<y.first+1<<" "<<y.second+1<<" "<<mask<<endl;
					}
					else if(grid[y.first][y.second]=='*')
					{
            vector<pii>::iterator it=find(bag.begin(),bag.end(),pii(y.first,y.second));
            int va=it-bag.begin();
						int mask1=(mask)|(1<<va);
              Q.push(ppi(y,mask1));
						  dp[y.first][y.second][mask1]=dp[x.first][x.second][mask]+1;
              dp[y.first][y.second][mask]=dp[y.first][y.second][mask1];
              //cout<<y.first+1<<" "<<y.second+1<<" "<<mask1<<endl;
						if(endgame==mask1)
            {
							return dp[y.first][y.second][mask1];
            }
					}
        }
			}
		}
	}
return -1;
}

int main()
{
	cin>>w>>h;
  while(w!=0 && h!=0)
  {
    bag.clear();
    dirty=0;
    pii source;
	  for(int i=0;i<h;i++)
	  {
		  for(int j=0;j<w;j++)
		  {
			  cin>>grid[i][j];
			  if(grid[i][j]=='o')
			  {
			  	source=pii(i,j);
			  }
			  else if(grid[i][j]=='*')
			  {
			  	dirty++;
          bag.emplace_back(pii(i,j));
			  }
        for(int k=0;k<16;k++)
			  {
				  	dp[i][j][k]=-1;
			  }
		  }
	  }
  //cout<<dirty<<endl;
	  endgame=(1<<(dirty))-1;
  //cout<<endgame<<endl;
	  int ans=bfs(source);
	  cout<<ans<<endl;
    cin>>w>>h;
  }
return 0;
}