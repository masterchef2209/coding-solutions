#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		if(m>=n)
		{
			if(n&1)
				cout<<'R'<<endl;
			else
				cout<<'L'<<endl;
		}
		else
		{
			if(m&1)
				cout<<'D'<<endl;
			else
				cout<<'U'<<endl;
		}
	}
return 0;
}