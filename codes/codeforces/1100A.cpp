#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> arr(n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	int ans=INT_MIN;
	for(int b=1;b<=n;b++)
	{
		int sum1=0;
		for(int i=b;i<=n;i+=k)
		{
				sum1+=(arr[i]);
		}
		for(int i=b-k;i>=1;i-=k)
		{
				sum1+=(arr[i]);
		}
		int sum2=sum-sum1;
		if(abs(sum2)>ans)
		{
			ans=abs(sum2);
		}
	}
	cout<<ans<<endl;
return 0;
}