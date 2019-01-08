#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;
	string s;
	cin>>s;
	int p=1;
	int ans=0;
	while(p<n)
	{
		int flag=0;
		for(int i=min(n,p+(d));i>p;i--)
		{
			if(s[i-1]=='1')
			{
				flag=1;
				p=i;
				ans++;
				break;
			}
		}
		if(flag==0)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
return 0;
}