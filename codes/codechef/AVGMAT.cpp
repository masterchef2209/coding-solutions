#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
	cin>>n>>m;
	int FFirst[90005],SSecond[90005];
	int aa=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char a;
			cin>>a;
			if(a-'0'==1)
			{
				FFirst[aa]=i;
				SSecond[aa]=j;
				aa++;
			}
		}
	}
	int ans[600]={0};
	for(int i=0;i<aa;i++)
	{
		for(int j=i+1;j<aa;j++)
		{
			int x=abs(FFirst[i] - FFirst[j])+abs(SSecond[i] - SSecond[j]);
			ans[x]++;
		}
	}
	for(int ii=1;ii<=n+m-2;ii++)
	{
		cout<<ans[ii]<<" ";
	}
	cout<<endl;
	}
return 0;
}