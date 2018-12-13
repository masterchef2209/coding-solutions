#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int flag=0,flag1=0;
		cin>>s;
		int n1=s.length();
		int n=n1;
		int i=0;
		int countr=0,countg=0;
		while(n--)
		{
			if(s[i]=='R' && s[(i+1)%n1]=='R')
			{
        flag1=1;
				if(s[(i+2)%n1]=='R')
				{
					flag=1;
					break;
				}
				else
				{
					countr++;
				}
			}
			else if(s[i]=='G' && s[(i+1)%n1]=='G')
			{
        flag1=1;
				if(s[(i+2)%n1]=='G')
				{
					flag=1;
					break;
				}
				else
				{
					countg++;
				}
			}
			i=(i+1)%s.length();
		}
    if(flag1==0)
      cout<<"yes"<<endl;
    else
    {
      if(flag==1)
			cout<<"no"<<endl;
		else
		{
			if(countr==1 && countg==1)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
    }
	}
return 0;
}