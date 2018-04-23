/*the number of trailing zeroes in n! is equal to power of 5 in that number*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		long ans=0;
		for(long i=1;pow(5,i)<=n;i++)
		{
			ans=ans+(n/pow(5,i));
		}
		cout<<ans<<endl;
	}
return 0;
}