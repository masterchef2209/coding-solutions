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
		if(n!=m)
		{
			cout<<"Alice"<<endl;
			continue;
		}
		int A[n],B[m];
		int ff=0,ff1=0;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
			if(A[i]==0)
				ff=1;
		}
		for(int j=0;j<m;j++)
		{
			cin>>B[j];
			if(B[j]==0)
				ff1=1;
		}
		if(ff1==1 && ff==1)
		{
			cout<<"Bob"<<endl;
			continue;
		}
		else if(ff1==0 || ff==0)
		{
			cout<<"Alice"<<endl;
			continue;
		}
		sort(A,A+n);
		sort(B,B+m);
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(A[i]!=B[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<"Alice"<<endl;
		else
			cout<<"Bob"<<endl;
	}	
return 0;
}