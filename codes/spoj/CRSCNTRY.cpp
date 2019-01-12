#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001];

int main()
{
	int d;
	cin>>d;
	while(d--)
	{
		vector<int>agnes;
		int temp;
		cin>>temp;
		while(temp!=0)
		{
			agnes.emplace_back(temp);
			cin>>temp;
		}
		vector<vector<int> >tom;
		string s;
		getline(cin,s);
		getline(cin,s);
		//cout<<s<<endl;
		while(s[0]!='0')
		{
			vector<int> ttemp;
			istringstream ss(s);
			int aa;
			while(ss>>aa)
			{
				if(aa==0)
					break;
				ttemp.emplace_back(aa);
			}
			tom.emplace_back(ttemp);
			getline(cin,s);
			//cout<<s<<endl;
		}
		int mm=-1;
		agnes.emplace_back(0);
		int m=agnes.size();
		for(int loop=0;loop<tom.size();loop++)
		{
		    tom[loop].emplace_back(0);
			int n=tom[loop].size();
			for(int k=0;k<n;k++)
			{
				dp[k][m-1]=0;
			}
			for(int k=0;k<m;k++)
			{
				dp[n-1][k]=0;
			}
			for(int i=n-2;i>=0;i--)
			{
				for(int j=m-2;j>=0;j--)
				{
					if(agnes[j]==tom[loop][i])
					{
						dp[i][j]=1+dp[i+1][j+1];
					}
					else
					{
						dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
					}
				}
			}
			if(dp[0][0]>mm)
			{
				mm=dp[0][0];
			}
		}
		cout<<mm<<endl;
	}
return 0;
}