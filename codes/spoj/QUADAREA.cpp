#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		double s=(a+b+c+d)/2;
		double ans=sqrt((s-a)*(s-b)*(s-c)*(s-d));
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
return 0;
}
