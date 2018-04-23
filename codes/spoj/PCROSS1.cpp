#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,c1,c2;
		cin>>m>>n>>c1>>c2;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==c1||j==c2)
					cout<<"*";
				else
					cout<<".";
			}
			cout<<endl;
		}
	}
return 0;
}