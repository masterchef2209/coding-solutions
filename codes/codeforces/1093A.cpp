#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		if(x<=7)
			cout<<1<<endl;
		else
		{
			if(x%7==0)
				cout<<x/7<<endl;
			else
				cout<<x/7+1<<endl;
		}
	}
return 0;
}