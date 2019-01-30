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
		char s[n];
		cin>>s;
		int count=0,count1=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				count1++;
			}
			if(i==0)
			{
				if(s[i]=='0' && s[i+1]=='0')
				{
					s[i]='1';
					count++;
				}
			}
			else if(i==n-1)
			{
				if(s[i]=='0' && s[i-1]=='0')
				{
					s[i]='1';
					count++;
				}
			}
			else
			{
				if(s[i]=='0' && s[i+1]=='0' && s[i-1]=='0')
				{
					s[i]='1';
					count++;
				}
			}
		}
		if(count1==0)
		{
			if(n&1)
				cout<<n/2+1<<endl;
			else
				cout<<n/2<<endl;
		}
		else
			cout<<count<<endl;
	}
return 0;
}