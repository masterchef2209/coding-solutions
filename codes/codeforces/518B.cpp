#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,t;
	cin>>s>>t;
	long long arr[52];
	memset(arr,0,sizeof(arr));
	for(long i=0;i<t.size();i++)
	{
		if(islower(t[i]))
		{
			arr[t[i]-'a']++;
		}
		else if(isupper(t[i]))
		{
			arr[t[i]-'A'+26]++;
		}
	}
	long long yay=0,whoops=0;
	vector<int>indices;
	for(long i=0;i<s.size();i++)
	{
		if(islower(s[i]))
		{
			if(arr[s[i]-'a']>0)
			{
				yay++;
				arr[s[i]-'a']--;
			}
			else
			{
				indices.push_back(i);
			}
		}
		else if(isupper(s[i]))
		{
			if(arr[s[i]-'A'+26]>0)
			{
				yay++;
				arr[s[i]-'A'+26]--;
			}
			else
			{
				indices.push_back(i);
			}
		}
	}
	for(auto i:indices)
	{
		if(islower(s[i]))
		{
			if(arr[s[i]-'a'+26]>0)
			{
				whoops++;
				arr[s[i]-'a'+26]--;
			}
		}
		else if(isupper(s[i]))
		{
			if(arr[s[i]-'A']>0)
			{
				whoops++;
				arr[s[i]-'A']--;
			}
		}
	}
	cout<<yay<<" "<<whoops;
return 0;
}