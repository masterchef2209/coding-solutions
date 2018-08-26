#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int m=INT_MIN;
		for(int i=0;i<=n-k;i++)
		{
			int sum=0;
			for(int j=i;j<i+k;j++)
			{
				sum+=arr[j];
			}
			if(sum>m)
			{
				m=sum;
			}
		}
		cout<<m<<endl;
	}
return 0;
}