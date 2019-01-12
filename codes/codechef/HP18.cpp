#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n,a,b;
		cin>>n>>b>>a;
		long cA=0,cB=0,common=0;
		for(int u=0;u<n;u++)
		{
			long temp;
			cin>>temp;
			if(temp%a==0 && temp%b==0)
			{
				common++;
			}
			else if(temp%a==0)
				cA++;
			else if(temp%b==0)
				cB++;
		}
		if(cA>cB)
			cout<<"ALICE"<<endl;
		else if(cA==cB)
		{
			if(common==0)
				cout<<"ALICE"<<endl;
			else
				cout<<"BOB"<<endl;
		}
		else
			cout<<"BOB"<<endl;
	}
return 0;
}