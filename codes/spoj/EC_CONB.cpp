#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		long long x;
		cin>>x;
		if(x&1)
			cout<<x<<endl;
		else
		{
			long long num=0;
			int i=(int)log2(x)+1;
			i=i-1;
			while(i>=0)
			{
				if(x&1)
				{
					num+=pow(2,i);
				}
				x>>=1;
				i--;
			}
      cout<<num<<endl;
		}
	}
return 0;
}