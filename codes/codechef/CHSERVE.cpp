#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long p1,p2,k;
		cin>>p1>>p2>>k;
		long p=p1+p2;
		long temp=p/10;
		long rr=p%10;
		if((temp)%2==0)
		{
			if(rr==0 || rr==1 || rr==4 || rr==5 || rr==8 || rr==9)
			{
				cout<<"CHEF"<<endl;
			}
			else
			{
				cout<<"COOK"<<endl;
			}
		}
		else
		{
			if(rr==0 || rr==1 || rr==4 || rr==5 || rr==8 || rr==9)
			{
				cout<<"COOK"<<endl;
			}
			else
			{
				cout<<"CHEF"<<endl;
			}

		}
	}
return 0;
}