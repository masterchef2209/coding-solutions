#include<bits/stdc++.h>
using namespace std;
//not accepted
#define int long long

signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,k;
		cin>>n>>a>>b>>k;
		int lcm=(a/__gcd(a,b))*b;
		if(((n/a)+(n/b)-2*(n/lcm) )>=k)
			cout<<"Win"<<endl;
		else
			cout<<"Lose"<<endl;
	}
return 0;
}