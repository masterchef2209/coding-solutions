#include<bits/stdc++.h>
using namespace std;
#define MM 1000000007

long long dp[200005][3];
long long cnt[3];

int main()
{
	memset(cnt,0,sizeof(cnt));
	long long n;
	long long l,r;
	cin>>n>>l>>r;
	if(r-l<20)
	{
		for(int i=l;i<=r;i++)
		{
			cnt[i%3]++;
		}
	}
	else
	{
		long long left=l,right=r;
		while(left%3!=0)
		{
			cnt[left%3]++;
			left++;
		}
		while(right%3!=0)
		{
			cnt[right%3]++;
			right--;
		}
		cnt[0]++;
		long long temp=(right-left)/3;
		for(int i=0;i<3;i++)
		{
			cnt[i]+=temp;
		}
	}
	dp[1][0]=cnt[0];
	dp[1][1]=cnt[1];
	dp[1][2]=cnt[2];
	for(long long i=2;i<=n;i++)
	{
		for(long long j=0;j<3;j++)
		{
			if(j==0)
			{
				dp[i][j]= ((((cnt[0]%MM)*(dp[i-1][0]%MM))%MM+(cnt[2]%MM)*(dp[i-1][1]%MM))%MM+(cnt[1]%MM)*(dp[i-1][2]%MM) )%MM ;
			}
			else if(j==1)
			{
				dp[i][j]=((((cnt[1]%MM)*(dp[i-1][0]%MM))%MM+(cnt[0]%MM)*(dp[i-1][1]%MM))%MM+(cnt[2]%MM)*(dp[i-1][2]%MM) )%MM ;
			}
			else if(j==2)
			{
				dp[i][j]=((((cnt[2]%MM)*(dp[i-1][0]%MM))%MM+(cnt[1]%MM)*(dp[i-1][1]%MM))%MM+(cnt[0]%MM)*(dp[i-1][2]%MM) )%MM ;
			}
		}
	}
	cout<<dp[n][0]<<endl;
return 0;
}