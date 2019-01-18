#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p,count=0;
		cin>>n>>p;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cout<<i<<" "<<j<<endl;
				count++;
				if(count== 2*n+p)
					goto outt;
			}
		}
		outt:;
	}
return 0;
}