#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int flag=0;
		int arr[n+1],arr1[n+1];
		arr[0]=arr1[0]=-1;
		vector<vector<int> >vv(100005);
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			vv[arr[i]].push_back(i);
			arr1[i]=arr[i];
		}
		sort(arr1+1,arr1+n+1);
		for(int i=1;i<=n;i++)
		{
			if(vv[i].size()>=2)
			{
				int cc=0;
				for(int j=0;j<vv[i].size();j++)
				{
					if(binary_search(arr1+1,arr1+1+n,vv[i][j]))
						cc++;
					if(cc==2)
					{
						cout<<"Truly Happy\n";
						goto xx;
					}
				}
			}
		}
		cout<<"Poor Chef\n";
		xx:;
	}
return 0;
}