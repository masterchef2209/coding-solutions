#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isPrime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
return true;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>arr(n);
	int ans1=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		ans1+=arr[i];
	}
	int mmn=*min_element(arr.begin(),arr.end());
	int ans=ans1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=arr[i];j++)
		{
			if(arr[i]%j==0)
			{
				int temp=ans1-mmn-arr[i];
				temp+=(mmn*j+arr[i]/j);
				ans=min(temp,ans);
			}
		}
	}
	cout<<ans<<endl;
return 0;
}