#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	while(cin>>s1)
	{
		cin>>s2;
		int arr[26]={0},arr1[26]={0};
		for(int i=0;i<s1.length();i++)
		{
			arr[s1[i]-'a']++;
		}
		for(int i=0;i<s2.length();i++)
		{
			arr1[s2[i]-'a']++;
		}
		string xx("");
		for(int i=0;i<26;i++)
		{
			int l=min(arr[i],arr1[i]);
			while(l--)
			{
				xx+=('a'+i);
			}
		}
		cout<<xx<<endl;
	}
return 0;
}