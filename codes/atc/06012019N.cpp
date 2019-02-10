#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int dp[n+1][n+1];
	int arr[n+1];int prefix[n+1];
	arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		dp[i][i]=0;
		dp[i-1][i]=arr[i-1]+arr[i];
	}
	partial_sum(arr,arr+1+n,prefix);
	for(int i=n;i>=1;i--)
	{
		for(int j=i+2;j<=n;j++)
		{
			dp[i][j]=LLONG_MAX;
			for(int k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+prefix[j]-prefix[i-1]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
return 0;
}