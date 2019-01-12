#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		long long n,x,y,z;
		long long num,den;
		int t;
		cin>>n>>t>>x>>y>>z;
		if(t==1)
		{
			if(y==z)
			{
				num=z;den=2*n+1;
			}
			else if(x==z)
			{
				num=z;den=2*n+1;
			}
			else
			{
				num=2*n+1-z;den=2*n+1;
			}
		}
		else if(t==2)
		{
			if(x==y || z==y)
			{
				num=1;den=2*n+1;
			}
			else
			{
				num=2*n+1-(x+z);den=2*n+1;
			}
		}
		else if(t==3)
		{
			if(x==y)
			{
				num=x;den=2*n+1;
			}
			else if(x==z)
			{
				num=x;den=2*n+1;
			}
			else
			{
				num=2*n+1-x;den=2*n+1;
			}
		}
		else if(t==4)
		{
			if(x==y || z==y)
			{
				num=1;den=2*n+1;
			}
			else
			{
				num=2*n+1-(x+z);den=2*n+1;
			}
		}
		long long temp=__gcd(num,den);
		cout<<num/temp<<" "<<den/temp<<endl;
	}
return 0;
}