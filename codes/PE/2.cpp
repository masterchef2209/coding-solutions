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
		long long sum=0;
		long long a=1;
		long long b=1;
		long long c=2;
		while(c<n)
		{
			sum+=c;
			int x=3;
			while(x--)
			{
				a=b;
				b=c;
				c=a+b;
			}
		}
		cout<<sum<<endl;
	}
return 0;
}