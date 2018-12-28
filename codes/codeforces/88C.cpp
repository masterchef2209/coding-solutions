#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;
	if(a==b)
	{
		cout<<"Equal";
		exit(0);
	}
	long long lcm=(a*b)/__gcd(a,b);
	long long a1=lcm/a-1;
	long long b1=lcm/b-1;
	if(a>b)
	{
		a1++;
	}
	else
		b1++;
	if(a1>b1)
		cout<<"Dasha";
	else if(a1==b1)
		cout<<"Equal";
	else
		cout<<"Masha";
}