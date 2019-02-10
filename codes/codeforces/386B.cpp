#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<char>cc(n);
	string s;
	cin>>s;
	if(n&1)
	{
		int i=1,j=n/2;
		int ii=1;
		cc[j]=s[0];
		while(j+ii<n)
		{
			if(j-ii>=0)
				cc[j-ii]=s[i];
			i++;
			if(j+ii<n)
				cc[j+ii]=s[i];
			i++;
			ii++;
		}
	}
	else
	{
		int i=1,j=n/2-1;
		int ii=1;
		cc[j]=s[0];
		while(j+ii<n)
		{
			if(j+ii<n)
				cc[j+ii]=s[i];
			i++;
			if(j-ii>=0)
				cc[j-ii]=s[i];
			i++;
			ii++;
		}
	}
	for(int i=0;i<n;i++)
		cout<<cc[i];
	return 0;
}