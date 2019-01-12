#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
	{
	    int n,m;
	    cin>>n>>m;
		int mm=-1;
		int grid[n+1][m+1];
		if(n==2 && m==1)
		{
		    
			mm=1;
			grid[1][1]=1;
			grid[2][1]=1;
		}
		else if(n==2)
		{
		    
			mm=min(3,m);
			for(int j=1;j<=m;j++)
			{
				grid[1][j]=(j-1)%3+1;
				grid[2][j]=(j-1)%3+1;
			}
		}
		else if(m==2)
		{
		    
			mm=min(3,n);
			for(int j=1;j<=n;j++)
			{
				grid[j][1]=(j-1)%3+1;
				grid[j][2]=(j-1)%3+1;
			}
		}
		else
		{
		    
		for(int k=1;k<n;k++)
		{
			int l=1;
			int mode=0;
			if(	((int)ceil(k/2.0))&1	)
				mode=0;
			else mode=1;
			for(int i=k+1,j=1;i<=n && j<=m;i++,j++)
			{
				if(	mode==0	)
				{
					if(l&1)
					{
						grid[i][j]=2;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
					else
					{
						grid[i][j]=4;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
				}
				else
				{
					if(l&1)
					{
						grid[i][j]=1;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
					else
					{
						grid[i][j]=3;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
				}
				l++;
			}
		}
		for(int k=1;k<=m;k++)
		{
			int l=1;
			int mode=0;
			if(	((int)ceil(k/2.0))&1	)
				mode=0;
			else mode=1;
			for(int i=1,j=k;i<=n && j<=m;i++,j++)
			{
				if(mode==0)
				{
					if(l&1)
					{
						grid[i][j]=1;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
					else
					{
						grid[i][j]=3;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
				}
				else
				{
					if(l&1)
					{
						grid[i][j]=2;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
					else
					{
						grid[i][j]=4;
						if(mm<grid[i][j])
						{
							mm=grid[i][j];
						}
					}
				}
				l++;
			}
		}
		}
		cout<<mm<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
return 0;
}