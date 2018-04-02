#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	int ar1[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar1[i];
	}
	cin>>m;
	int ar2[m];
	for(int i=0;i<m;i++)
	{
		cin>>ar2[i];
	}
	int z=(n<m)?n:m;
	for(int i=0;i<z;i++)
	{
		if(ar1[i]==ar2[i])
			cout<<i+1<<" ";
	}
return 0;
}