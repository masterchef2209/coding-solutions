#include<bits/stdc++.h>
using namespace std;

char grid[120][120];
long long d[120][120][16];
int r,c;
#define pii pair<long long,long long>
#define ppi pair<pii,long long>

int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};

inline bool ingrid(pii&o)
{
	return (o.first<r && o.first>=0 && o.second<c && o.second>=0);
}

long long bfs(pii&o)
{
	pii u,v;
	long long umask,vmask;
	d[o.first][o.second][0]=0;
	queue<ppi>Q;
	Q.push(make_pair(o,0));
	while(!Q.empty())
	{
		u=Q.front().first;
		umask=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++)
		{
			v=make_pair(u.first+dr[i],u.second+dc[i]);
			if(ingrid(v) && grid[v.first][v.second]!='#')
			{
				if(grid[v.first][v.second]=='X')
					return d[u.first][u.second][umask]+1;
				if(d[v.first][v.second][umask]==-1)
				{
					vmask=umask;
					if(islower(grid[v.first][v.second]))
					{
						switch(grid[v.first][v.second])
						{
							case 'b': vmask|=0x01; break;
							case 'y': vmask|=0x02; break;
							case 'r': vmask|=0x04; break;
							case 'g': vmask|=0x08; break;
						}
						Q.push(make_pair(v,vmask));
						d[v.first][v.second][vmask]=d[u.first][u.second][umask]+1;
					}
					else if(isupper(grid[v.first][v.second]))
					{
						switch(grid[v.first][v.second])
						{
							case 'B': if(umask&0x01) Q.push(make_pair(v,umask)); break;
							case 'Y': if(umask&0x02) Q.push(make_pair(v,umask)); break;
							case 'R': if(umask&0x04) Q.push(make_pair(v,umask)); break;
							case 'G': if(umask&0x08) Q.push(make_pair(v,umask)); break;
						}
						d[v.first][v.second][umask]=d[u.first][u.second][umask]+1;
					}
					else
					{
						Q.push(make_pair(v,umask));
						d[v.first][v.second][umask]=d[u.first][u.second][umask]+1;
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int x0,y0;
	cin>>r>>c;
	while(r!=0 && c!=0)
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]=='*')
				{
					x0=i;
					y0=j;
				}
				for(int k=0;k<16;k++)
				{
					d[i][j][k]=-1;
				}
			}
		}
    pair<long long,long long> pos=make_pair(x0,y0);
		long long ans=bfs(pos);
		if(ans==-1)
		{
			cout<<"The poor student is trapped!\n";
		}
		else
		{
			cout<<"Escape possible in "<<ans<<" steps.\n";
		}
    cin>>r>>c;
	}
	return 0;
}