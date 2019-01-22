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
	int value=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i].second>>arr[i].first;
		value+=arr[i].first;
	}
	int dp[n+1][value+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=value;j++)
		{
			dp[i][j]=INT_MAX;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=value;j++)
		{
			if(j<arr[i].first)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=min(dp[i-1][j],arr[i].second+dp[i-1][j-arr[i].first]);
			}
		}
	}
	int gg=0;
	for(int i=0;i<=value;i++)
	{
		if(dp[n][i]<=w)
			gg=i;
	}
	cout<<gg<<endl;
return 0;
}