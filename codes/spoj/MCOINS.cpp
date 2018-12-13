#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k,l,m;
	cin>>k>>l>>m;
	while(m--)
	{
		int n;
		cin>>n;
		char dp[n+1];
		int i=0,p=0;
		while(i<k)
		{
			if(!(p&1))
			{
				dp[i]='L';
			}
			else
			{
				dp[i]='W';
			}
			p++;i++;
		}
		while(i<l)
		{
			if(dp[i-1]=='W' && dp[i-k]=='W')
			{
				dp[i]='L';
			}
			else
			{
				dp[i]='W';
			}
      i++;
		}
		while(i<=n)
		{
			if(dp[i-1]=='W' && dp[i-k]=='W' && dp[i-l]=='W')
			{
				dp[i]='L';
			}
			else
			{
				dp[i]='W';
			}
      i++;
		}
    if(dp[n]=='L')
      cout<<'B';
    else
      cout<<'A';
	}
return 0;
}