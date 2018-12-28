#include<bits/stdc++.h>
using namespace std;

int main()
{
	int s,x1,x2;
	cin>>s>>x1>>x2;
	int dirt;
	int rvt,rvm;
	cin>>rvt>>rvm;
	int p;
	cin>>p>>dirt;
	if(x1<=x2)
	{
		if(dirt==1)
		{
			if(p>x1)
			{
					cout<<min(rvm*(x2-x1),rvt*(2*s+x2-p));
			}
			else
			{
					cout<<min(rvm*(x2-x1),rvt*(x2-p));
			}
		}
		else
		{
				cout<<min(rvm*(x2-x1),rvt*(p+x2));
		}
	}
	else
	{
		if(dirt==-1)
		{
			if(p<x1)
			{
					cout<<min(rvm*(x1-x2),rvt*(2*s+p-x2));
			}
			else
			{
					cout<<min(rvm*(x1-x2),rvt*(p-x2));
			}
		}
		else
		{
				cout<<min(rvm*(x1-x2),rvt*(2*s-p-x2));
		}
	}
return 0;
}