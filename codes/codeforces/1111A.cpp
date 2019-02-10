#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	string t;
	cin>>t;
	if(s.size()!=t.size())
	{
		cout<<"No"<<endl;
		return 0;
	}
	string ss(""),tt("");
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
		{
			ss+="1";
		}
		else
			ss+="0";
		if(t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u')
		{
			tt+="1";
		}
		else
			tt+="0";	
	}
	if(ss!=tt)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
return 0;
}