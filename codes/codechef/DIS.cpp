#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int flag=0;
		int a[n+1],b[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>1)
			{
				if(a[i]==0)
					flag=1;
			}
			else
			{
				if(a[i]!=0)
					flag=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			if(i<n)
			{
				if(b[i]==0)
					flag=1;
			}
			else
			{
				if(b[i]!=0)
					flag=1;
			}
		}
		int small=(b[1]);
		if(a[1]!=0 || b[n]!=0)
		{
			cout<<"No"<<endl;
			continue;
		}
		if(b[1]!=a[n])
		{
			cout<<"No"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if( ((a[i]+b[i])<small) || ((a[i]+small)<b[i]) || ((small+b[i])<a[i]))
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
return 0;
}
