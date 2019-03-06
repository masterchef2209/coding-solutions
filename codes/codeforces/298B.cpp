#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int d;
	cin>>d;
	int arr[n+1][m+1];
	int flag=0;
	int sum=0;
	vector<int>bag(n*m);
	int k=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>arr[i][j];
			bag[k++]=(arr[i][j]);
		}
	}
	int val=arr[1][1]%d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(arr[i][j]%d!=val)
				flag=1;
		}
	}
	if(flag==1)
		cout<<-1<<endl;
	else
	{
		sort(bag.begin(),bag.end());
		int median=bag[bag.size()/2];
		int sum1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sum1+=abs(median-arr[i][j]);
			}
		}
		cout<<sum1/d<<endl;
	}
return 0;
}