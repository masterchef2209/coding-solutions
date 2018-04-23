#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	while(n--)
	{
		int x,y;
		int z=0;
		int i=0,j=0;
		cin>>x>>y;
		if(x==y || y==x-2)
		{
			while(z<=20000)
			{
				if(i==x && j==y)
					break;
				if(z%4==0)
				{
					i++;j++;
				}
				else if(z%4==1)
				{
					i++;j--;
				}
				else if(z%4==2)
				{
					i++;j++;
				}
				else if(z%4==3)
				{
					i--;j++;
				}
				z++;
			}
			cout<<z<<endl;
		}
		else
		{
			cout<<"No Number"<<endl;
		}
	}
return 0;
}