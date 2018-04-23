#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		long b;
		cin>>b;
		int k=1;
		while(b>0)
		{
			if(b&1)
			{
				k=((k%10)*(a%10))%10;
			}
			b=b>>1;
			a=((a%10)*(a%10))%10;
		}
		cout<<k<<endl;
	}
return 0;
}