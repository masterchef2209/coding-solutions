#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	set<char>ss;
	for(int i=0;i<s.length();i++)
	{
		ss.insert(s[i]);
	}
	int ll=ss.size();
	if(ll&1)
	{
		cout<<"IGNORE HIM!";
	}
	else
	{
		cout<<"CHAT WITH HER!";
	}
return 0;
}