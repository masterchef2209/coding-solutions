#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int h,w;
int dp[1002][1002];
char grid[1002][1002];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			dp[i][j]=0;
			cin>>grid[i][j];
		}
	}
	for(int i=1;i<=h;i++)
	{
		if(grid[i][1]=='.')
		{
			dp[i][1]=1;
		}
		else
			break;
	}
	for(int j=1;j<=w;j++)
	{
		if(grid[1][j]=='.')
		{
			dp[1][j]=1;
		}
		else
			break;
	}
	for(int i=2;i<=h;i++)
	{
		for(int j=2;j<=w;j++)
		{
			if(grid[i][j]=='.')
			{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
			}
		}
	}
	cout<<dp[h][w]<<endl;
return 0;
}