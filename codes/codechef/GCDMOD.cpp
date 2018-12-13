#include<bits/stdc++.h>
using namespace std;
#define MM 1000000007

long long gpow(long long a,long long b,long long mod = MM)
{
	long long res=1;
	while(b)
	{
		if(b&1)
			res=((__int128)res*a)%mod;
		a=((__int128)a*a)%mod;
		b>>=1;
	}
	return res;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,n;
		cin>>a>>b>>n;
		if(a==b)
			cout<<(gpow(a,n)+gpow(b,n))%MM<<endl;
		else
		{
			long long d=(gpow(a,n,a-b)+gpow(b,n,a-b))%(a-b);
			cout<<__gcd(d,a-b)<<endl;
		}
	}
	return 0;
}