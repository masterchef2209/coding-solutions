#include<bits/stdc++.h>
using namespace std;

#define int long long

int bpow(int n,int m)
{
	int result=1;
	int x=3%m;
	while(n>0)
	{
		if(n&1)
			result=(result*x)%m;
		n>>=1;
		x=(x*x)%m;
	}
return result;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int temp=bpow(n,m);
	if(temp==0)
		cout<<m-1<<endl;
	else
		cout<<temp-1<<endl;
return 0;
}