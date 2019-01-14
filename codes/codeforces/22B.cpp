#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
int far[25][25];
char grid[25][25];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(grid[i][j]=='1')
			{
				far[i][j]=j-1;
			}
			else if(j==m-1)
			{
				far[i][j]=j;
			}
			else
			{
				far[i][j]=far[i][j+1];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int dist=INF;
			for(int r2=i;r2<n && grid[r2][j]=='0';r2++)
			{
				dist=min(dist,far[r2][j]);
				out=max(out,2*(r2-i+dist-j+2));
			}
		}
	}
	cout<<out<<endl;
return 0;
}