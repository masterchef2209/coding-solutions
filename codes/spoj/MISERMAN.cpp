#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			if(i>0)
			{
				if(j==0)
				{
					arr[i][j]=arr[i][j]+min(arr[i-1][j],arr[i-1][j+1]);
				}
				else if(j==m-1)
				{
					arr[i][j]=arr[i][j]+min(arr[i-1][j],arr[i-1][j-1]);
				}
				else
				{
					arr[i][j]=arr[i][j]+min(arr[i-1][j],min(arr[i-1][j+1],arr[i-1][j-1]));
				}
			}
		}
	}
	int mm=INT_MAX;
	for(int i=0;i<m;i++)
	{
		if(arr[n-1][i]<mm)
		{
			mm=arr[n-1][i];
		}
	}
	cout<<mm<<endl;
return 0;
}