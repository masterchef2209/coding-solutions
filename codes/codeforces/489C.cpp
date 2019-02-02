#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,s;
	cin>>m>>s;
	if(m==1 && s==0)
	{
		cout<<"0 0";
		return 0;
	}
	vector<int>biggie;
	int sum=s;
	int count=0;
	while(1)
	{	
		if(count==m)
			break;
		if(sum>=9)
		{
			biggie.emplace_back(9);
			sum-=9;
		}
		else if(sum>0)
		{
			biggie.emplace_back(sum);
			sum=0;
		}
		else
			biggie.emplace_back(0);
		count++;
	}
	if(sum>0)
	{
		cout<<"-1 -1";
		return 0;
	}
	if(biggie[m-1]!=0)
	{
	    for(int i=m-1;i>=0;i--)
	        cout<<biggie[i];
	    cout<<" ";
	    for(int j=0;j<m;j++)
	        cout<<biggie[j];
	   return 0;
	}
	int k=m-1;
	int a,b;
    while(k>=0 && biggie[k]==0)
	{
	    k--;
	}
	if(k==-1)
	{
	    cout<<"-1 -1";
		return 0;
	}
	else
	{
	    a=1;
	    b=biggie[k]-1;
	}
	for(int i=m-1;i>=0;i--)
	{
	    if(i==m-1)
	        cout<<a;
	   else if(i==k)
	        cout<<b;
	   else
			cout<<biggie[i];
	}
	cout<<" ";
	for(int j=0;j<m;j++)
		cout<<biggie[j];
return 0;
}