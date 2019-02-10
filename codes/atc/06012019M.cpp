#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int dp[101][100002];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j]=0;
		}
	}
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum<k)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<=arr[0];i++)
	{
		dp[0][i]=1;
	}
	for(int i=1;i<n;i++)
	{
		int sum=0;
		for(int j=0;j<=arr[i];j++)
		{
			sum=(dp[i-1][j]+sum)%MOD;
			dp[i][j]=sum;
		}
		for(int j=arr[i]+1;j<=k;j++)
		{
			sum=(sum-dp[i-1][j-arr[i]-1]+MOD)%MOD;
			sum=(dp[i-1][j]+sum)%MOD;
			dp[i][j]=sum;
		}
	}
	cout<<dp[n-1][k];
return 0;
}