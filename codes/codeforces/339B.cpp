#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(int u=0;u<m;u++)
	{
		cin>>arr[u];
	}
	long long ans=0;
	int prev=1;
	for(int i=0;i<m;i++)
	{
		if(arr[i]>prev)
		{
			ans+=(arr[i]-prev);
		}
		else if(arr[i]<prev)
		{
			ans+=(arr[i]+n-prev);
		}
		prev=arr[i];
	}
	cout<<ans;
return 0;
}