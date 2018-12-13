#include<bits/stdc++.h>
using namespace std;

long X,Y;

bool func(long a,long b)
{
	if(a<0 || b<0)
		return false;
	if(a%X==0 && b%Y==0)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		long n,m;
		cin>>n>>m>>X>>Y;
		if(func(n-1,m-1) || func(n-2,m-2))
			cout<<"Chefirnemo"<<endl;
		else
			cout<<"Pofik"<<endl;
	}
return 0;
}