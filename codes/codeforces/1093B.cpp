#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int arr[26];
		int bulb=1;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<s.size();i++)
		{
			if(i>0)
			{
				if(s[i]!=s[i-1])
					bulb=0;
			}
			arr[s[i]-'a']++;
		}
		if(bulb==1)
			cout<<-1<<endl;
		else
		{
			for(int i=0;i<26;i++)
			{
				int count=arr[i];
				while(count--)
				{
					cout<<(char)('a'+i);
				}
			}
			cout<<endl;
		}
	}
return 0;
}