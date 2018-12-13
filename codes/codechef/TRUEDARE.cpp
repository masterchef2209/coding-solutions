#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int tr,dr,ts,ds;
		int flag=0;
		cin>>tr;
		int truth[101]={0},dare[101]={0};
		for(int i=0;i<tr;i++)
		{
			int k;
			cin>>k;
			truth[k]=1;
		}
    cin>>dr;
		for(int i=0;i<dr;i++)
		{
			int k;
			cin>>k;
			dare[k]=1;
		}
    cin>>ts;
		for(int i=0;i<ts;i++)
		{
			int x;
			cin>>x;
			if(truth[x]==0)
			{
				flag=1;
			}
		}
    cin>>ds;
			for(int i=0;i<ds;i++)
			{
				int x;
				cin>>x;
				if(dare[x]==0)
				{
					flag=1;
				}
			}
    // for(int i=1;i<=tr;i++)
    // {
    //   cout<<truth[tr]<<" ";
    // }
    // cout<<endl;
    // for(int j=1;j<=dr;j++)
    // {
    //   cout<<dare[dr]<<" ";
    // }
    // cout<<endl;
		if(flag==1)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
return 0;
}