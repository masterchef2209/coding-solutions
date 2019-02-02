#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int sum=0;
	for(int i=0;i<n/2;i++)
	{
		sum+=(arr[i]+arr[n-i-1])*(arr[i]+arr[n-i-1]);
	}
	cout<<sum;
return 0;
}