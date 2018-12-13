#include<bits/stdc++.h>
using namespace std;

long long summultipleof(long long n,int k)
{
	long long p=(n-1)/k;
	return (k*p*(p+1))/2;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout<<summultipleof(n,3)+summultipleof(n,5)-summultipleof(n,15)<<endl;

	}
return 0;
}