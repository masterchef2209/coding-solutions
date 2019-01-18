#include<bits/stdc++.h>
using namespace std;

int sieve[612000];
vector<long long>primes;
void precompute()
{
	memset(sieve,0,sizeof(sieve));
	for(long long i=2;i*i<=612000;i++)
	{
		if(sieve[i]==0)
		{
			for(int j=2*i;j<=612000;j+=i)
			{
				sieve[j]=1;
			}
		}
	}
	for(long long i=2;i<=612000;i++)
	{
		if(sieve[i]==0)
			primes.emplace_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	precompute();
	int t;
	cin>>t;
	while(t--)
	{
		long long n,i=3,nn;
		cin>>n;
		cout<<7*5<<" ";
		long long count=n-2,c=0,j=0;
		while(count)
		{
			if(((j)&1))
				nn=3;
			else
				nn=2;
			cout<<primes[i]*nn<<" ";
			if(!(c&1))
			{
				i++;
			}
			else
				j++;
			c++;
			count--;
		}
			if(((j)&1))
				nn=3;
			else
				nn=2;
		if(n%2==0)
			cout<<primes[i]*5<<" ";
		else
			cout<<5*nn<<" ";
		cout<<endl;
	}
	return 0;
}