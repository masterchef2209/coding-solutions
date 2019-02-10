#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	int ss[n];
	for(int i=0;i<k;i++)
	{
		cin>>ss[i];
	}
	int dp[k+1];
	int limit=ss[0];
	for(int i=0;i<ss[0];i++)
	{
		dp[i]=0;
	}
	for(int i=limit;i<=k;i++)
	{
		int flag=0;
		for(int j=0;j<n;j++)
		{
			if((i-ss[j])>=0 && dp[i-ss[j]]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			dp[i]=1;
		else
			dp[i]=0;
	}
	if(dp[k])
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;
return 0;
}