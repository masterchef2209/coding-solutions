#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s1[150],s2[150];
  scanf("%s",s1);
  scanf("%s",s2);
  int n1=sizeof(s1)/sizeof(s1[0]);
  int n2=sizeof(s2)/sizeof(s2[0]);
	for(int i=0;i<n1;i++)
	{
		s1[i]=tolower(s1[i]);
	}
	for(int i=0;i<n2;i++)
	{
		s2[i]=tolower(s2[i]);
	}
	int u=strcmp(s1,s2);
	if(u<0)
	{
		cout<<-1;
	}
	else if(u>0)
	{
		cout<<1;
	}
	else
		cout<<0;
return 0;
}