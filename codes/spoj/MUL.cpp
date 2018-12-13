#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cpp_int a,b;
		cin>>a>>b;
		cpp_int ans=a*b;
		cout<<ans<<endl;
	}
return 0;
}