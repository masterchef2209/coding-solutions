#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long s,a,b,c;
		cin>>s>>a>>b>>c;
		long long z=s/c;
		long long x=z/a;
		z+=x*b;
    cout<<z<<endl;
	}
return 0;
}