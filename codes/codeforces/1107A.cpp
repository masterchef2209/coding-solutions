#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n==2)
		{
			if(s[0]<s[1])
			{
				cout<<"YES\n"<<2<<endl<<s[0]<<" "<<s[1]<<endl;
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else if(n==3)
		{
			cout<<"YES\n"<<2<<endl<<s[0]<<" "<<s[1]<<s[2]<<endl;
		}
		else
		{
			if(n&1)
			{
				cout<<"YES\n"<<2<<endl;
				for(int i=0;i<n/2;i++)
				{
					cout<<s[i];
				}
				cout<<" ";
				for(int j=n/2;j<n;j++)
				{
					cout<<s[j];
				}
				cout<<endl;
			}
			else
			{
				cout<<"YES\n"<<2<<endl;
				for(int i=0;i<n/2-1;i++)
				{
					cout<<s[i];
				}
				cout<<" ";
				for(int j=n/2-1;j<n;j++)
				{
					cout<<s[j];
				}
				cout<<endl;
			}
		}
	}
return 0;
}