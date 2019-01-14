#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int dp[5000][5000],suf[5000][5000];
int out=0;
char s[5000];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>s[i];
	}
	dp[0][0]=1;
	for(int i=1;i<N;i++)
	{
		suf[i-1][N-1]=dp[i-1][N-1];
		for(int j=N-2;j>=0;j--)
		{
			suf[i-1][j]=(dp[i-1][j]+suf[i-1][j+1])%MOD;
		}
		for(int j=0;j<N;j++)
		{
			if(s[i-1]=='f')
			{
				if(j!=0)
					dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=0;
			}
			else
			{
				dp[i][j]=suf[i-1][j];
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		out=(out+dp[N-1][i])%MOD;
	}
	cout<<out;
return 0;
}