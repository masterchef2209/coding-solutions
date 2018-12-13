#include<bits/stdc++.h>
using namespace std;
//partially accepted
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<1<<" "<<1<<" "<<2<<" "<<3<<endl;
		long long x1;
		cin>>x1;
		cout<<1<<" "<<2<<" "<<3<<" "<<4<<endl;
		long long x2;
		cin>>x2;
		long long x3=x1^x2;
		cout<<1<<" "<<1<<" "<<4<<" "<<5<<endl;
		long long x4;
		cin>>x4;
		long long x5=x3^x4;
		long long i=x5-4;
		cout<<2<<" ";
		while(n--)
		{
			cout<<i<<" ";
			i++;
		}
		cout<<endl;
		long long verdict;
		cin>>verdict;
		if(verdict==-1)
			break;
	}
return 0;
}