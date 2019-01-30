#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s("");
	int flag=1;
	for(int i=0;i<n;i++)
	{
		string b;
		cin>>b;
		s+=b;
	}
	vector<int>factors;
	for(int i=3;i<=n;i++)
	{
		if(n%i==0)
			factors.emplace_back(i);
	}
	for(int i=0;i<factors.size();i++)
	{
		int side=factors[i];
		int jum=n/side;
		for(int j=0;j<jum;j++)
		{
			int temp=j;
			int count=0;
			for(int u=0;u<side;u++,temp+=jum)
			{
				if(s[(temp+j)%n]=='1')
					count++;
			}
			if(count==side)
			{
			    //cout<<side<<" "<<j<<endl;
				flag=0;
				goto label;
			}
		}
	}
	label:;
	if(flag==1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
return 0;
}