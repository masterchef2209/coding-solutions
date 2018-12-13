#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long s;
	cin>>n>>s;
	long long sum=0;
	vector<long long>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	if(sum<s)
		cout<<-1;
	else
	{
		sort(v.begin(),v.end());
		long long s1=s;
		for(int j=n-1;j>0;j--)
		{
			if(s1-(v[j]-v[0])>=0)
			{
				s1-=(v[j]-v[0]);
				v[j]=v[0];
				if(s1==0)
					break;
			}
			else
			{
				s1=0;
				v[j]-=s1;
				break;
			}
		}
		if(s1>0)
		{
			long long qu=s1/n;
			long long rem=s1%n;
			if(rem==0)
				v[0]-=qu;
			else
				v[0]-=(qu+1);
		}
		sort(v.begin(),v.end());
		cout<<v[0];
	}
	return 0;
}