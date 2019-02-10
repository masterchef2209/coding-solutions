#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=(arr[i]-1);
		}
		sum+=1;
		cout<<sum<<endl;
	}
return 0;
}