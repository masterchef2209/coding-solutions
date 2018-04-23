#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
	if(n==1)
		return 1;
	else
		return n*n+fun(n-1);
}

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		cout<<fun(n)<<endl;
		cin>>n;
	}
return 0;
}