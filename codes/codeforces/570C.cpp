#include<bits/stdc++.h>
using namespace std;

char s[300005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int doubledot=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.' && s[i+1]=='.')
			doubledot++;
	}
	while(m--)
	{
		int x;
		char c;
		cin>>x>>c;
		if(c=='.' && s[x-1]!='.')
		{
			if(x-2>=0 && s[x-2]=='.')
				doubledot++;
			if(x<n && s[x]=='.')
				doubledot++;
		}
		else if(c!='.' && s[x-1]=='.')
		{
			if(x-2>=0 && s[x-2]=='.')
				doubledot--;
			if(x<n && s[x]=='.')
				doubledot--;
		}
		s[x-1]=c;
		cout<<doubledot<<endl;
	}
return 0;
}