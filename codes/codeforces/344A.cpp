#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans=1;
	int temp=-1;
	while(n--)
	{
		char c1,c2;
		cin>>c1>>c2;
    int a,b;
    a=c1-'0';
    b=c2-'0';
		if(temp==a)
			ans++;
		temp=b;
	}
	cout<<ans;
return 0;
}