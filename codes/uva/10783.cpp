#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		int a,b;
		cin>>a>>b;
		int sum=0;
		for(int i=a;i<=b;i++)
		{
			if(i&1)
				sum+=i;
		}
		cout<<"Case "<<u<<": "<<sum<<endl;
	}
return 0;
}