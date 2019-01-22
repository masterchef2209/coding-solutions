#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	int dp[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0]=0;
	for(int i=1;i<min(k,n);i++)
	{
		dp[i]=abs(arr[i]-arr[0]);
	}
	for(int j=k;j<n;j++)
	{
		dp[j]=INT_MAX;
		for(int h=1;h<=k;h++)
		{
			dp[j]=min(dp[j],dp[j-h]+abs(arr[j]-arr[j-h]));
		}
	}
	cout<<dp[n-1]<<endl;
return 0;
}