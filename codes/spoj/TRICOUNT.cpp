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
		cout<<((2*n*(n+2)*(2*n+1)-1+(long long)pow(-1,n))/16)<<endl;;
	}
return 0;
}