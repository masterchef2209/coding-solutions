#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long a=pow((n*(n+1))/2,2);
        long long b=(n*(n+1)*(2*n+1))/6;
        cout<<a-b<<endl;
	}
return 0;
}