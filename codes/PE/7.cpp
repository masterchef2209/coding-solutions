#include<bits/stdc++.h>
using namespace std;

vector<long long> vv;
int sieve[1000006];

void precompute()
{
	for(int i=2;i*i<=1000000;i++)
	{
		if(!sieve[i])
		{
			for(int j=2*i;j<=1000000;j+=i)
			{
				sieve[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++)
	{
		if(!sieve[i])
		{
			vv.push_back(i);
		}
	}
}

int main()
{
	memset(sieve,0,sizeof(sieve));
	precompute();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		n=n-1;
		vector<long long>::iterator it=vv.begin();
		while(n--)
		{
			it++;
		}
		cout<<*it<<endl;
	}
return 0;
}