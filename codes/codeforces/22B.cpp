#include<bits/stdc++.h>
using namespace std;
//incomplete
int dp[26][26][26][26];

int main()
{
	int n,m;
	cin>>n>>m;
	char grid[n][m];
	memset(dp,0,sizeof(arr[0][0][0][0])*26*26*26*26);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='0')
			{
				dp[i][i][j][j]=4;
			}
		}
	}
	for(int x1=0;x1<n;x1++)
	{
		for(int y1=0;y1<m;y1++)
		{
			for(int x2=x1;x2<n;x2++)
			{
				for(int y2=y1;y2,m;y2++)
				{

				}
			}
		}
	}
return 0;
}