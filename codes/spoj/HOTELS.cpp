#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int ans=0;
	int sum=0;
	int i=0,j=0;
	while(j<n)
	{
		sum+=arr[j];
		while(sum>m)
		{
			sum-=arr[i];
			i++;
		}
		if(sum>ans)
		{
			ans=sum;
		}
		j++;
	}
	cout<<ans<<endl;
return 0;
}

