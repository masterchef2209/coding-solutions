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
		int n=s.length();
		int flag=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=s[n-i-1])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
return 0;
}