#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	int y,y1[15][35],y2[15][35];
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<35;j++)
		{
			y1[i][j]=0;
			y2[i][j]=0;
		}
	}
	cin>>n;
	int mm=LLONG_MIN;
	while(n--)
	{
		int m,d,p,t;
		cin>>m>>d>>p>>t;
		y=13;
		while(t--)
		{
			d--;
			if(d==0)
			{
				m--;
				if(m==0)
				{
					y=12;m=12;d=31;
				}
				if(m==2)
				{
					d=28;
				}
				else if(m==4 || m==6 || m==9 || m==11)
					d=30;
				else
					d=31;
			}
			if(y==13)
				y1[m][d]+=p;
			else
				y2[m][d]+=p;
			if(y1[m][d]>mm)
				mm=y1[m][d];
			if(y2[m][d]>mm)
				mm=y2[m][d];
		}
	}
	cout<<mm<<endl;
return 0;
}