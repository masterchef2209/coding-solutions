#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	long long n;
	cin>>n;
	while(n--)
	{
		long long x,d;
		cin>>x>>d;
		long long y=(x*x-d*d)/4;
		if(x*x-4*y>=0)
		{
			long long r1=(x+sqrt(x*x-4*y));
			long long r2=(x-sqrt(x*x-4*y));
			if(r1&1 || r2&1 || r1<0 || r2<0)
			{
				cout<<"impossible"<<endl;
			}
			else
			{
				r1=r1/2;
				r2=r2/2;
				cout<<r1<<" "<<r2<<endl;
			}
		}
		else
		{
			cout<<"impossible"<<endl;
		}
	}
return 0;
}