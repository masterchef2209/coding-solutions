#include<bits/stdc++.h>
using namespace std;


int dp[101][101][101];
int arr[101];

int main()
{
	ifstream cin("taming.in");
	ofstream cout("taming.out");
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			for(int k=0;k<n;k++)
			{
				dp[i][j][k]=1e9;
			}
		}
	}
	if(arr[0]==0)
	{
		dp[0][1][0]=0;
	}
	else
	{
		dp[0][1][0]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(k==0) 
				{
					for(int k2=0;k2<n;k2++)
					{
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][k2]);
					}
					if(arr[i]!=k)
					{
						dp[i][j][k]++;
					}
				}
				else
				{
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k-1]);
					if(arr[i]!=k)
					{
						dp[i][j][k]++;
					}
				}
			}
		}
	}
	for(int j=1;j<n+1;j++)
	{
		int out=1e9;
		for(int k=0;k<n;k++)
		{
			out=min(out,dp[n-1][j][k]);
		}
		cout<<out<<endl;
	}
return 0;
}