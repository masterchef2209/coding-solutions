#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,w;
	cin>>n>>w;
	pair<int,int> arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr+1,arr+n+1);
	int dp[n+1][w+1];
	for(int j=0;j<=w;j++)
	{
		if(j<arr[1].first)
			dp[1][j]=0;
		else
		{
			dp[1][j]=arr[1].second;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(j<arr[i].first)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],arr[i].second+dp[i-1][j-arr[i].first]);
			}
		}
	}
	cout<<dp[n][w]<<endl;
	
return 0;
}