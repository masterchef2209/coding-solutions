#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char grid[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	int ans=0;
	int ss=0;
	for(int i=1;i+1<n;i+=1)
	{
	    if(i+1>=n)
	        break;
		for(int j=1;j+1<n;j+=1)
		{
		    //cout<<i<<" "<<j<<endl;
			if(grid[i][j]=='X' && grid[i-1][j-1]=='X' && grid[i-1][j+1]=='X' && grid[i+1][j-1]=='X' && grid[i+1][j+1]=='X')
			{	
			    ans++;
			}
		}
	}
	cout<<ans;
return 0;
}