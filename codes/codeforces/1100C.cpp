#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535

int main()
{
	double n,r;
	double ang;
	cin>>n>>r;
	ang=PI/n;
	cout<<fixed<<setprecision(10)<<(r*sin(ang))/(1-sin(ang));
return 0;
}