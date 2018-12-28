#include<bits/stdc++.h>
using namespace std;

int main()
{
	double n;
	while(cin>>n)
	{
    if(n==0)
      break;
		long long temp=n;
		double a=floor(cbrt(temp));
		double ans=(n-a*a*a)/(3*a*a);
		cout<<fixed<<setprecision(4)<<a+ans<<endl;
	}
return 0;
}