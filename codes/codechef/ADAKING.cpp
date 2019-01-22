#include<bits/stdc++.h>
using namespace std;

int r,c,k;

inline bool ingrid(pair<int,int>&a)
{
	return (a.first>0 && a.second>0 && a.first<=8 && a.second<=8);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		cin>>r>>c>>k;
		int count=0; 
		for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				pair<int,int>p=make_pair(i,j);
				if(ingrid(p) && (abs(r-p.first)<=k && abs(c-p.second)<=k))
					count++;
			}
		}
		cout<<count<<endl;
	}
return 0;
}