#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	a-=x;
	if(a<0)
	{
		cout<<"NO";
		return 0;
	}
	int d=a+b;
	d-=y;
	if(d<0)
	{
		cout<<"NO";
		return 0;
	}
	int e=d+c;
	e-=z;
	if(e<0)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
return 0;
}