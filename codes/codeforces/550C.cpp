#include<bits/stdc++.h>
using namespace std;

int main()
{
	int flag=0;
	string ans;
	string s;
	cin>>s;
	if(s.find("0")!=string::npos)
	{
		cout<<"YES\n"<<0;
		return 0;
	}
	else if(s.find("8")!=string::npos)
	{
		cout<<"YES\n"<<8;
		return 0;
	}
	else
	{
		for(int i=0;i<s.size();i++)
		for(int j=i+1;j<s.size();j++)
			{
				string temp("");
				temp+=s[i];
				temp+=s[j];
				int x=stoi(temp);
				if(x%8==0)
				{
					flag=1;
					ans=temp;
					break;
				}
			}
		if(flag)
		{
			cout<<"YES\n"<<ans;
			return 0;
		}
	}
	for(int i=0;i<s.size();i++)
		for(int j=i+1;j<s.size();j++)
			for(int k=j+1;k<s.size();k++)
			{
				string temp("");
				temp+=s[i];
				temp+=s[j];
				temp+=s[k];
				int x=stoi(temp);
				if(x%8==0)
				{
					flag=1;
					ans=temp;
					break;
				}
			}
	if(flag)
		cout<<"YES\n"<<ans;
	else
		cout<<"NO";
return 0;
}