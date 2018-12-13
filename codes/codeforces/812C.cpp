#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int S;
int arr[N];
long long arr1[N];
long long sum;
bool func(int k)
{
	for(int i=1;i<=n;i++)
	{
		arr1[i]=arr[i]+1LL*k*i;
	}
	sort(arr1+1,arr1+n+1);
	sum=0;
	for(int i=1;i<=k;i++)
	{
		sum+=arr1[i];
	}
	return sum<=S;
}

int main()
{
	cin>>n>>S;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int lo=0;
	int hi=n;
	while(lo<hi)
	{
		int mid=lo+hi+1>>1;
		if(func(mid))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
  	func(lo);
	cout<<lo<<" "<<sum;
return 0;
}