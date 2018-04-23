#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	while(x!=0 || y!=0 || z!=0)
	{
		if(y*2==x+z)
		{
			cout<<"AP ";
			cout<<z+(y-x)<<endl;
		}
		else
		{
			cout<<"GP ";
			cout<<z*(y/x)<<endl;
		}
		cin>>x>>y>>z;
	}
return 0;
}