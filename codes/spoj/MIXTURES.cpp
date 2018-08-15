#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int arr[n];
		pair<int,int> dp[n][n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
      dp[i][i].first=arr[i];
      dp[i][i].second=0;
		}
		int l=1;
		while(l<n)
		{
			int i=0;
			int j=l;
			for(;j<n;i++,j++)
			{
        int m=INT_MAX;
        int x;
				for(int k=i;k<j;k++)
				{
					int temp=(dp[i][k].first*dp[k+1][j].first)+dp[i][k].second+dp[k+1][j].second;
          if(temp<m)
          {
            m=temp;
            x=(dp[i][k].first+dp[k+1][j].first)%100;
          }
				}
        dp[i][j].second=m;
        dp[i][j].first=x;
			}
			l++;
		}
		cout<<dp[0][n-1].second<<endl;		
	}
return 0;
}
