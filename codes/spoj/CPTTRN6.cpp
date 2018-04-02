#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l,c,h,w;
		cin>>l>>c>>h>>w;
		for(int i=1;i<=(l+(l+1)*h);i++)
		{
			for(int j=1;j<=(c+(c+1)*w);j++)
			{
				if(i%(h+1)==0)
				{
					if(j%(w+1)==0)
					{
						cout<<"+";
					}
					else
					{
						cout<<"-";
					}
				}
				else
				{
					if(j%(w+1)==0)
					{
						cout<<"|";
					}
					else
					{
						cout<<".";
					}
				}
			}
			cout<<endl;
		}
	}
return 0;	
}