#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long> arr(100005);
	vector<long long> ar1(100005);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>arr[0];
		ar1[0]=arr[0];
		if(arr[0]>=n-1)
		{
			cout<<1<<endl;
			continue;
		}
		for(int i=1;i<n;i++)
		{
			cin>>arr[i];
			ar1[i]=ar1[i-1]+arr[i];
		}
		int i=0;
		int day=0;
		while(i<n-1)
		{
			i+=ar1[i];
			day++;
		}
		cout<<day<<endl;
	}
return 0;
}