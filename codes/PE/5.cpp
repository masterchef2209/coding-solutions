#include<bits/stdc++.h>
using namespace std;

map<int,int> func(int n)
{
	map<int,int>mm;
	for(int i=2;i<=sqrt(n);i++)
	{
		while(n%i==0)
		{
			n=n/i;
			mm[i]++;
		}
	}
	if(n>1)
		mm[n]++;
	return mm;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<int,int>mm1;
		for(int i=2;i<=n;i++)
		{
			auto mm=func(i);
			map<int,int>::iterator it;
			for(it=mm.begin();it!=mm.end();it++)
			{
				if(mm1.find(it->first)==mm1.end())
				{
					mm1[it->first]=it->second;
				}
				if(mm1[it->first]<it->second)
				{
					mm1[it->first]=it->second;
				}
			}
		}
    map<int,int>::iterator it1;
		long long ans=1;
		for(it1=mm1.begin();it1!=mm1.end();it1++)
		{
			ans*=pow(it1->first,it1->second);
		}
		cout<<ans<<endl;
	}
return 0;
}