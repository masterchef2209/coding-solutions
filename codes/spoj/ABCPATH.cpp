#include<bits/stdc++.h>
using namespace std;
int h,w;
vector< vector<char> > table(51,vector<char>(51));
vector< vector<int> > arr(51,vector<int>(51,-1));
vector< pair<int,int> > As;

bool inRange(int i,int j)
{
	if(i>0 && i<=h && j>0 && j<=w)
		return true;
	return false;
}

int func(int i,int j,int count)
{
	if(arr[i][j]!=-1)
		return arr[i][j];
	vector<int>vv;
	int flag=0;
	if(inRange(i-1,j-1) && table[i-1][j-1]-table[i][j]==1)
	{
		int xx=func(i-1,j-1,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(inRange(i-1,j) && table[i-1][j]-table[i][j]==1)
	{
		int xx=func(i-1,j,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(inRange(i-1,j+1) && table[i-1][j+1]-table[i][j]==1)
	{
		int xx=func(i-1,j+1,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(inRange(i,j-1) && table[i][j-1]-table[i][j]==1)
	{
		int xx=func(i,j-1,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(inRange(i,j+1) && table[i][j+1]-table[i][j]==1)
	{
		int xx=func(i,j+1,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(inRange(i+1,j-1) && table[i+1][j-1]-table[i][j]==1)
	{
		int xx=func(i+1,j-1,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(inRange(i+1,j) && table[i+1][j]-table[i][j]==1)
	{
		int xx=func(i+1,j,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(inRange(i+1,j+1) && table[i+1][j+1]-table[i][j]==1)
	{
		int xx=func(i+1,j+1,count+1);
		flag=1;
		vv.push_back(xx);
	}
	if(flag==0)
		return arr[i][j]=count;
	else
		return arr[i][j]=*max_element(vv.begin(),vv.end());
}

int main()
{
	cin>>h>>w;
	int test=0;
	while(h!=0 || w!=0)
	{
		test++;
		for(int i=1;i<=50;i++)
		{
			for(int j=1;j<=50;j++)
			{
				arr[i][j]=-1;
			}
		}
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				cin>>table[i][j];
				if(table[i][j]=='A')
				{
					As.push_back(make_pair(i,j));
				}
			}
		}
		vector< pair<int,int> >::iterator it;
		int mm=INT_MIN;
		if(As.empty())
		{
			mm=0;
		}
		else
		{
			for(it=As.begin();it!=As.end();it++)
			{
				int i=it->first;
				int j=it->second;
				int z=func(i,j,1);
				if(z>mm)
				{
					mm=z;
				}
			}
		}
		cout<<"Case "<<test<<": "<<mm<<endl;
	As.clear();
	cin>>h>>w;
	}
return 0;
}