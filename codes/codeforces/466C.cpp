#include<bits/stdc++.h>
using namespace std;

//not accepted
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	long arr[n];
	long long dp[n+1][n+1];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int count=0;
	for(int i=1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
				long long sum1=0,sum2=0,sum3=0;
				if(dp[0][i]==-1)
				{
					sum1=accumulate(arr,arr+i,sum1);
					dp[0][i]=sum1;
				}
				if(dp[i][j]==-1)
				{
					sum2=accumulate(arr+i,arr+j,sum2);
					dp[i][j]=sum2;
				}
				if(dp[j][n]==-1)
				{
					sum3=accumulate(arr+j,arr+n,sum3);
					dp[j][n]=sum3;
				}
				if(dp[0][i]==dp[i][j] && dp[i][j]==dp[j][n])
					count++;
		}
	}
	cout<<count;
return 0;
}