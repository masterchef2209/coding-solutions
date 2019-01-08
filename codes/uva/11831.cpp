#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

int n,m,s;

char grid[102][102];
char nesw[4]={'N','E','S','W'};


inline bool ingrid(ii &a)
{
	return a.first>=0 && a.second>=0 && a.first<n && a.second<m;
}


int main()
{
	while(cin>>n>>m>>s)
	{
		if(n==0 && m==0 && s==0)
			break;
		int x,y;
		int count=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]>='A' && grid[i][j]<='Z')
				{
					x=i;
					y=j;
				}
			}
		}
		int dd;
		switch(grid[x][y])
		{
			case 'N':dd=0;break;
			case 'L':dd=1;break;
			case 'S':dd=2;break;
			case 'O':dd=3;break;
		}
		string seq;
		cin>>seq;
		int ans=0;
		for(int i=0;i<s;i++)
		{
      //cout<<x<<" "<<y<<" "<<nesw[dd]<<" "<<grid[x][y]<<endl;
			if(seq[i]=='D')
			{
				dd=(dd+1)%4;
			}
			else if(seq[i]=='E')
			{
				dd=dd-1;
				if(dd==-1)
					dd=3;
			}
			else if(seq[i]=='F')
			{
				int tx=x,ty=y;
				switch(dd)
				{
					case 0:tx=x-1;break;
					case 1:ty=y+1;break;
					case 2:tx=x+1;break;
					case 3:ty=y-1;break;
				}
				ii pp=make_pair(tx,ty);
				if(ingrid(pp) && grid[tx][ty]!='#')
				{
					x=tx;y=ty;
					if(grid[x][y]=='*')
					{
						count++;
						grid[x][y]='.';
					}
				}
			}
		}
    //cout<<x<<" "<<y<<" "<<nesw[dd]<<" "<<grid[x][y]<<endl;
		cout<<count<<endl;
	}
return 0;
}