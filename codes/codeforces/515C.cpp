#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<int,int>mm;
	for(int i=0;i<s.length();i++)
	{
		int xx=s[i]-'0';
		if(xx>1)
		{
			if(xx==4)
			{
				mm[2]+=2;
				mm[3]++;
			}
			else if(xx==8)
			{
				mm[2]+=3;
				mm[7]++;
			}
			else if(xx==6)
			{
					mm[3]++;
					mm[5]++;
			}
			else if(xx==9)
			{
					mm[3]+=2;
					mm[2]++;
					mm[7]++;
			}
			else
			{
				mm[xx]++;
			}
		}
	}
	map<int,int>::reverse_iterator it;
	for(it=mm.rbegin();it!=mm.rend();it++)
	{
		int e=it->second;
		while(e--)
		{
			cout<<it->first;
		}
	}
return 0;
}