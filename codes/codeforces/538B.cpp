#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char s[10];
	cin>>s;
	int xx=-1;
	for(int i=0;i<strlen(s);i++)
	{
		xx=max(xx,s[i]-'0');
	}
	cout<<xx<<endl;
	for(int i=0;i<xx;i++)
	{
		int flag=0;
		for(int j=0;j<strlen(s);j++)
		{
			if(s[j]=='0')
			{
			    if(flag==1)
				    cout<<0;
			}
			else
			{
				cout<<1;
				s[j]-=1;
				flag=1;
			}
		}
		cout<<" ";
	}
return 0;
}