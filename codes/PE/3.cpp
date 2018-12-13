#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long maxprime=-1;
		while(n%2==0)
		{
			maxprime=2;
			n>>=1;
		}
		for(long long i=3;i<=sqrt(n);i++)
		{
			while(n%i==0)
			{
				maxprime=i;
				n=n/i;
			}
		}
		if(n>2)
			maxprime=n;
		cout<<maxprime<<endl;
	}
return 0;
}