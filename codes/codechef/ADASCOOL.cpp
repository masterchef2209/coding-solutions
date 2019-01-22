#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(n%2==1 && m%2==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
return 0;
}