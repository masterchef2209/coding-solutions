#include<bits/stdc++.h>
using namespace std;
//not accepted
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int n;
		cin>>n;
		long long A[n+1][n+1],B[n+1][n+1];
		int flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>A[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>B[i][j];
				
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(A[i][j]==B[i][j])
				{
					;
				}
				else if(A[i][j]==B[j][i])
				{
					for(int k=0;k<n;k++)
					{
						swap(A[k][j],A[j][k]);
					}
				}
				else
					flag=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(A[i][j]!=B[i][j])
					flag=0;
			}
		}
		if(flag)
		{
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
return 0;
}
