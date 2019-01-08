#include<bits/stdc++.h>
using namespace std;

int grid[1000][18279];
string formula[1000][18279];
bool done[1000][18279];

int solve(int r,int c)
{
	if(done[r][c])
		return grid[r][c];
	string temp("");
	for(unsigned int i=0;i<formula[r][c].size();i++)
	{
		if(formula[r][c][i]=='+' || formula[r][c][i]=='=')
			temp+=" ";
		else
			temp+=formula[r][c][i];
	}
	formula[r][c]=temp;
	istringstream ss(temp);
	string s;
	int sum=0;
	while(ss>>s)
	{
		int r1=0,c1=0;
		for(unsigned int i=0;i<s.size();i++)
		{
			if(isdigit(s[i]))
			{
				r1=r1*10+(s[i]-'0');
			}
			else
			{
				c1=c1*26+(s[i]-'A'+1);
			}
		}
		sum+=solve(r1,c1);
	}
	done[r][c]=true;
return (grid[r][c]=sum);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>c>>r;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cin>>formula[i][j];
				done[i][j]=false;
				if(isdigit(formula[i][j][0]))
				{
					done[i][j]=true;
					grid[i][j]=stoi(formula[i][j]);
				}
			}
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cout<<solve(i,j);
				if(j<c)
					cout<<" ";
			}
			cout<<endl;
		}
	}
return 0;
}