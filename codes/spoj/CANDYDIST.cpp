#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long n;
	cin>>n;
	while(n!=0)
	{
		unsigned long long count[n],candy[n];
	for(int i=0;i<n;i++)
	{
		cin>>count[i];
	}
	for(int j=0;j<n;j++)
	{
		cin>>candy[j];
	}
	sort(count,count+n);
	sort(candy,candy+n,greater<unsigned long long>());
	unsigned long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(candy[i]*count[i]);
	}
	cout<<ans<<endl;
	cin>>n;
	}
return 0;
}