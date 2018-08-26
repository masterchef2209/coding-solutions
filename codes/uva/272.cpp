#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s;
	int c=0;
	while(scanf("%c",&s)!=EOF)
	{
		if(s=='"')
		{
			if(c&1)
			{
				cout<<"''";
			}
			else
			{
				cout<<"``";
			}
			c++;
		}
		else
		{
			cout<<s;
		}
	}
return 0;
}