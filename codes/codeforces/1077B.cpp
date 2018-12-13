#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int x=0;
	for(int i=2;i<n;i++)
	{
		if(arr[i]==0 && arr[i-1]==1 && arr[i+1]==1)
		{
			x++;
			arr[i+1]=0;
		}
	}
	cout<<x;
return 0;
}