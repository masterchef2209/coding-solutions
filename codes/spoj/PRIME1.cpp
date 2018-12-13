#include<bits/stdc++.h>
using namespace std;

bool isPrime(int i)
{
	if(i<=1)
		return false;
	if(i==2 || i==3)
		return true;
	for(int j=2;j<=sqrt(i);j++)
	{
		if(i%j==0)
			return false;
	}
return true;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		for(int i=m;i<=n;i++)
		{
			if(isPrime(i))
			{
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
return 0;
}