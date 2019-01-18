#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n+1],bulb[n+1];
	arr[0]=0;
	bulb[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>bulb[i];
	}
	long long A[n+1],B[n+1];
	A[0]=0;
	B[0]=0;
	for(int i=1;i<=n;i++)
	{
		A[i]=A[i-1]+arr[i];
		if(bulb[i]==1)
		{
			B[i]=B[i-1]+arr[i];
		}
		else
		{
			B[i]=B[i-1];
		}
	}
	long long sum=-1;
	for(int i=1;i<=n-k+1;i++)
	{
		sum=max(sum,B[n]-(B[i+k-1]-B[i-1])+(A[i+k-1]-A[i-1]) );
	}
	cout<<sum<<endl;
return 0;
}