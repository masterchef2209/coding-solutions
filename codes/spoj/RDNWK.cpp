#include<bits/stdc++.h>
using namespace std;
int dp[152][152][151];
int a[151];
int main()
{
	int t;
	cin>>t;
	for(int utest=1;utest<=t;utest++)
	{
		int n;
		cin>>n;
    memset(dp,1,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
        int tem;
        cin>>tem;
        if(tem==-1)
        {
          continue;
        }
				dp[i][j][0]=dp[j][i][0]=tem;
			}
			dp[i][i][0]=0;
		}
		int p;
		cin>>p;
    for(int i=1;i<=p;i++)
    {
      cin>>a[i];
    }
		for(int k=1;k<=p;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					 dp[i][j][a[k]] = min(dp[i][j][a[k-1]] , dp[i][a[k]][a[k-1]]+dp[a[k]][j][a[k-1]]) ;
				}
			}
		}
		int q;
		cin>>q;
		cout<<"Case "<<utest<<": ";
		while(q--)
		{
			int k,s,d;
			cin>>k>>s>>d;
      if(dp[s][d][a[k]]==16843009)
      {
        dp[s][d][a[k]]=-1;
      }
      if(s==d)
        cout<<0<<" ";
      else
			  cout<<dp[s][d][a[k]]<<" ";
		}
		cout<<endl;
	}
return 0;
}