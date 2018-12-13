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
		int arr[n][m];
		vector< pair<int,int> >pp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
        char a;
        cin>>a;
        arr[i][j]=a-'0';
				if(arr[i][j]==1)
					pp.push_back(make_pair(i,j));
			}
		}
    // for(int k=0;k<pp.size();k++)
    // {
    //   cout<<pp[k].first<<" "<<pp[k].second<<endl;
    // }
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int mm=INT_MAX;
				for(int k=0;k<pp.size();k++)
				{
					int xx=abs(pp[k].first-i)+abs(pp[k].second-j);
					if(xx<mm)
					{
						mm=xx;
					}
				}
				cout<<mm<<" ";
			}
			cout<<endl;
		}
	}
return 0;
}