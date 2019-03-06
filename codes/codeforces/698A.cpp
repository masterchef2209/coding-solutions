#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s("");
	for(int u=0;u<n;u++)
	{
	    string b;
	    cin>>b;
	    s+=b;
	}
	long long dp[101][3];
	dp[0][0]=0;
	dp[0][1]=dp[0][2]=0;
	for(int i=0;i<s.size();i++)
	{
		int j=i+1;
		if(s[i]=='0')
		{
			dp[j][0]=dp[j][1]=dp[j][2]=max({dp[j-1][0],dp[j-1][1],dp[j-1][2]});
		}
		else if(s[i]=='1')
		{
			dp[j][0]=dp[j][2]=max({dp[j-1][0],dp[j-1][1],dp[j-1][2]});
			dp[j][1]=1+max(dp[j-1][0],dp[j-1][2]);
		}
		else if(s[i]=='2')
		{
			dp[j][0]=dp[j][1]=max({dp[j-1][0],dp[j-1][1],dp[j-1][2]});
			dp[j][2]=1+max(dp[j-1][0],dp[j-1][1]);
		}
		else if(s[i]=='3')
		{
			dp[j][0]=max({dp[j-1][0],dp[j-1][1],dp[j-1][2]});
			dp[j][1]=1+max(dp[j-1][0],dp[j-1][2]);
			dp[j][2]=1+max(dp[j-1][0],dp[j-1][1]);
		}
	}
// 	for(int i=0;i<3;i++)
// 	{
// 	    for(int j=0;j<=s.size();j++)
// 	    {
// 	        cout<<dp[j][i]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	long long temp=max({dp[s.size()][0],dp[s.size()][1],dp[s.size()][2]});
	cout<< s.size() -temp;
return 0;
}