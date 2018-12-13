#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans=0;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]+arr[i+1]<k)
		{
			ans+=(k-(arr[i]+arr[i+1]));
			arr[i+1]+=(k-(arr[i]+arr[i+1]));
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
return 0;
}