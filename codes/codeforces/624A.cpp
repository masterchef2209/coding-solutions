#include<bits/stdc++.h>

using namespace std;
int main()
{
	double d,L,v1,v2;
	cin>>d>>L>>v1>>v2;
	double y=L-d;
	double x=v1+v2;
	double ans=y/x;
	printf("%.6lf",ans);
return 0;}