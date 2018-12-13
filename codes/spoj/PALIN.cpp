#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s1,s;
		cin>>s1;
		if(!isdigit(s1[s1.length()-1]))
		{
			s=s1.substr(0,s1.length()-1);
		}
		else
			s=s1;
		int n=s.length();
		int flag=0,fl9=0,count9=0;
		for(int k=0;k<n;k++)
		{
			if(s[k]!='9')
			{
				fl9=1;
				break;
			}
			else
				count9++;
		}
		if(fl9==0)
		{
			cout<<1;
			for(int i=0;i<count9-1;i++)
			{
				cout<<0;
			}
			cout<<1<<endl;
		}
		else
		{
		for(int i=n/2-1;i>=0;i--)
		{
			if(s[n-i-1]<s[i])
			{
				flag=1;
				break;
			}
			else if(s[i]<s[n-i-1])
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			int i;
			if(n%2==0)
				i=n/2-1;
			else
				i=n/2;
			while(s[i]=='9')
			{
				s[i]='0';
				i--;
			}
			s[i]++;
		}
		int j;
		if(n%2==0)
				j=n/2-1;
			else
				j=n/2;
		for(int i=0;i<=j;i++)
		{
			cout<<s[i];
		}
		for(int i=n/2-1;i>=0;i--)
		{
			cout<<s[i];
		}
		cout<<endl;
		}
	}
return 0;
}