#include<bits/stdc++.h>
using namespace std;

int dp[100005][3];

int main()
{
  int t=0;
	int n;
	cin>>n;
  while(n)
  {
    t++;
    int a,b,c;
  cin>>a>>b>>c;
	dp[1][0]=a;
	dp[1][1]=b;
	dp[1][2]=b+c;
	for(int i=2;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
    if(i==2)
    {
      dp[i][0]=a+dp[i-1][1];
		  dp[i][1]=min(b+dp[i-1][1],min(b+dp[i-1][2],b+dp[i][0]));
		  dp[i][2]=min(c+dp[i-1][1],min(c+dp[i-1][2],c+dp[i][1]));
    }
    else
    {
      dp[i][0]=min(a+dp[i-1][0],a+dp[i-1][1]);
		  dp[i][1]=min(b+dp[i-1][0],min(b+dp[i-1][1],min(b+dp[i-1][2],b+dp[i][0])));
		  dp[i][2]=min(c+dp[i-1][1],min(c+dp[i-1][2],c+dp[i][1]));
    }
	}
	cout<<t<<". "<<dp[n][1]<<endl;  
  cin>>n;
  }
	
return 0;
}