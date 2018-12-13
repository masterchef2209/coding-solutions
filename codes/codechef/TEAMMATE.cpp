#include<bits/stdc++.h>
using namespace std;

#define MM 1000000007

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long ans=1,p=0;
		long n;
		cin>>n;
		map<long,long>mm;
		while(n--)
		{
			long k;
			cin>>k;
			mm[k]++;
		}
		map<long,long>::iterator it;
		for(it=mm.begin();it!=mm.end();it++)
		{
			long c=it->second;
			p+=c;
			if(c%2==0)
			{
				if(p%2==1)
					ans=(ans%MM * c%MM)%MM;
				c=c-1;
			}
			while(c>=1)
			{
				ans=(ans%MM * c%MM)%MM;
				c-=2;
			}
		}
		cout<<ans<<endl;
	}
return 0;
}