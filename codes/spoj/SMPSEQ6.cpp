#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	int s[n],q[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>q[i];
	}
	for(int i=0;i<n;i++)
	{
		int flag=0;
		int l=(i-x>0)?(i-x):0;
		int r=(i+x<n)?(i+x):(n-1);
		for(int k=l;k<=r;k++)
		{
			if(s[i]==q[k])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<i+1<<" ";
	}
return 0;
}