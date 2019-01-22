#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k,t;
	cin>>n>>k>>t;
	long long sum=(n*k*t)/100;
	long long count=sum/k;
	for(int u=0;u<count;u++)
	{
		cout<<k<<" ";
	}
	if(count!=n)
		cout<<sum%k<<" ";
	int rem=n-(count+1);
	for(int u=0;u<rem;u++)
	{
		cout<<0<<" ";
	}
return 0;
}