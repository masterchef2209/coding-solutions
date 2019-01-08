#include<bits/stdc++.h>
using namespace std;
#define limit 1000007

long long ss[1000009];


void func()
{
	int sievebound=(limit-1)/2;
	int sieve[sievebound+1];
	memset(sieve,0,sizeof(sieve));
	int crosslimit=(abs(sqrt(limit))-1)/2;
	for(int i=1;i<=crosslimit;i++)
	{
		if(sieve[i]==0)
		{
			for(int j=2*i*(i+1);j<=sievebound;j+=(2*i+1))
				sieve[j]=1;
		}
	}
	long long sum=2;
	ss[2]=2;
	ss[1]=0;
	for(int i=1;i<=sievebound;i++)
	{
		if(sieve[i]==0)
		{
			sum+=(2*i+1);
		}
		ss[2*i+1]=sum;
		ss[2*i+2]=sum;
	}
}

int main()
{
	func();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<ss[n]<<endl;
	}
return 0;
}