#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
double dp[3001][3001];

signed main()
{
	cin>>n;
	double p[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	dp[1][0]=1-p[1];
	dp[1][1]=p[1];
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]*(1-p[i]);
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
		}
	}
	double ans=0;
	for(int k=n/2+1;k<=n;k++)
	{
		ans+=dp[n][k];
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
return 0;
}