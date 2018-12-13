#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans=0;
	while(n--)
	{
		int temp=0;
		int a,b,c;
		cin>>a>>b>>c;
		temp=a+b+c;
		if(temp>=2)
			ans++;
	}
	cout<<ans;
return 0;
}