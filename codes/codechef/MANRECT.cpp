#include<bits/stdc++.h>
using namespace std;
#define int long long
#define BIG 1000000000
//not accepted
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cout<<"Q "<<0<<" "<<0<<endl;
		int ab;
		cin>>ab;
		cout<<"Q "<<BIG<<" "<<0<<endl;
		int temp,ac;
		cin>>temp;
		ac=BIG-temp+ab;
		int a,b;
		cout<<"Q "<<(ac/2)<<" "<<0<<endl;
		cin>>b;
		a=ab-b;
		int c=ac-a;
		int temp1,cd;
		cout<<"Q "<<BIG<<" "<<BIG<<endl;
		cin>>temp1;
		cd=BIG-temp1+BIG;
		int d=cd-c;
		cout<<"A "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		int x;
		cin>>x;
		if(x<0)
			break;
	}
return 0;
}