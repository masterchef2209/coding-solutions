#include<bits/stdc++.h>
using namespace std;

int main()
{
	long n;
	cin>>n;
	while(n!=0)
	{
		vector<int> vv;
		for(int i=2;i<=sqrt(n);i++)
		{
			int c=0;
			while(n%i==0)
			{
				c++;
				n=n/i;
			}
			vv.push_back(c);
		}
		if(n>1)
		{
			vv.push_back(1);
		}
		long ans=1;
		for(int i=0;i<vv.size();i++)
		{
			ans*=(vv[i]+1);
		}
		int zz=ans%2;
		if(zz==0)
		{
			cout<<"no"<<endl;
		}
		else
		{
			cout<<"yes"<<endl;
		}
	cin>>n;
	}
return 0;
}