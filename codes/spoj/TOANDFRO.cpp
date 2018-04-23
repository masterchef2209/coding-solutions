#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		string s;
		cin>>s;
		int c=(s.length()/n);
		char arr[c][n];
		int i=0,j=0,k=0;
		while(k<s.length())
		{
			arr[i][j]=s[k];
			if(i%2==0)
			{
				if(j==n-1)
				{
					i++;
				}
				else
					j++;
			}
			else
			{
				if(j==0)
				{
					i++;
				}
				else
					j--;
			}
			k++;
		}

		for(int j=0;j<n;j++)
		{
			for(int i=0;i<c;i++)
			{
				cout<<arr[i][j];
			}
		}
		cout<<endl;
		cin>>n;
	}
return 0;
}