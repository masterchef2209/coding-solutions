#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int count=0;
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		count++;
		if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y')
		{
			ans=max(ans,count);
			count=0;
		}
	}
	count++;
	ans=max(ans,count);
	cout<<ans<<endl;
return 0;
}