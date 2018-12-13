#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
	long long n;
	while(cin>>n)
	{
		if(n<8)
		{
			cout<<"Impossible."<<endl;
		}
		else
		{
			if(n&1)
			{
				n=n-5;
				for(long long i=2;i<=n;i++)
				{
					if(isPrime(i) && isPrime(n-i))
					{
						cout<<2<<" "<<3<<" "<<i<<" "<<n-i<<endl;
						break;
					}
				}
			}
			else
			{
				n=n-4;
				for(long long i=2;i<=n;i++)
				{
					if(isPrime(i) && isPrime(n-i))
					{
						cout<<2<<" "<<2<<" "<<i<<" "<<n-i<<endl;
						break;
					}
				}
			}
		}
	}
return 0;
}