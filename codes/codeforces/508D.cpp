#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long sump=0,sumn=0;
	vector <long long> po,ne,all;
	for(int i=0;i<n;i++)
	{
		long long temp;
		cin>>temp;
		if(temp>=0)
		{
			po.push_back(temp);
			sump+=temp;
		}
		else
		{
			ne.push_back(temp);
			sumn+=temp;
		}
		all.push_back(temp);
	}
	if(all.size()==1)
	{
		cout<<all.front()<<endl;
	}
	else if(ne.empty())
	{
		cout<<sump-*min_element(po.begin(),po.end())*2<<endl;
	}
	else if(po.empty())
	{
		cout<<abs(sumn-*max_element(ne.begin(),ne.end())*2)<<endl;
	}
	else
	{
		cout<<(sump-sumn)<<endl;
	}
return 0;
}