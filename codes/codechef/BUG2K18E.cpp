#include<bits/stdc++.h>
using namespace std;

long long dp[100001];
long long arr[100001];
char ch[100001];
int n;

long long func(int i)
{
	if(dp[i]!=-1)
		return dp[i];
	if(i>=n)
		return 0;
	int j=0;
	if(i<n-1)
	{
		if(ch[i+1]=='J')
		{
			j=1;
		}
		else
		{
			j=0;
		}
	}
return dp[i]=max(arr[i]+func(i+1+j),func(i+1)); 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>ch[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<func(0)<<endl;
	}
return 0;
}