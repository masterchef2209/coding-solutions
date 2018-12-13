#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long d=-1;
	int flag=0;
	for(long long i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			d=i;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<1;
	else
	{
		if(d&1)
		{
			cout<<(1+(n-d)/2);
		}
		else
		{
			cout<<n/2;
		}
	}
return 0;
}