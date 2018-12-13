#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	k=k+1;
	for(int i=k;i>0;i--)
	{
		cout<<i<<" ";
	}
	for(int j=k+1;j<=n;j++)
	{
		cout<<j<<" ";
	}
return 0;
}