#include<bits/stdc++.h>
using namespace std;

long long func(long long n,long long k)
{
	if(k==0)
		return 1;
	if(k>n/2) return func(n,n-k);
	long long res=1;
	for(long long i=1;i<=k;i++)
	{
		res*=(n-i+1);
		res/=i;
	}
return res;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		if(n<=k)
			cout<<1<<endl;
		else
		{
			n=n-1;
			k=k-1;
			cout<<func(n,k)<<endl;
		}
	}
return 0;
}
