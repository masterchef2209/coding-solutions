#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	string s;
	cin>>s;
	int i=0,j=0;
	int ans=0;
	while(i<n && j<n)
	{
		while(i<n && s[i]==s[j])
		{
			i++;
		}
		sort(arr+j,arr+i,greater<int>());
		for(int h=j;h<min(i,j+k);h++)
		{
			ans+=arr[h];
		}
		j=i;
	}
	cout<<ans<<endl;
return 0;
}