#include<bits/stdc++.h>
using namespace std;
//not accepted
int main()
{
	int n,m;
	cin>>n>>m;
	if(n==0 || m==0 ||n==1)
	{
		cout<<n<<" "<<n;
	}
	else
	{
		int t1=n-(2*m);
		int t2=n-(m+1);
		if(t1<0)
		{
			t1=0;
		}
		if(t2<0)
		{
			t2=0;
		}
		cout<<t1<<" "<<t2;
	}
return 0;
}