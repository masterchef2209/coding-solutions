#include<bits/stdc++.h>
using namespace std;

int numPfactors(int i)
{
	int count=0;
	for(int j=2;j<=sqrt(i);j++)
	{
		if(i%j==0)
		{
			count++;
		}
		while(i%j==0)
		{
			i=i/j;
		}
	}
	if(i>1)
	{
		count++;
	}
return count;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<30<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<42<<endl;
			continue;
		}
		n=n-2;
		for(int i=43;i<=3000;i++)
		{
			int z=numPfactors(i);
			if(z>=3)
			{
				n--;
			}
			if(n==0)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
return 0;
}