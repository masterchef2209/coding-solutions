#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> >vv;

bool cmp(pair<int,int> &a,pair<int,int>&b)
{
	if(a.first==b.first)
	{
		if(a.first&1)
			return a.second<b.second;
		else
			return a.second>b.second;
	}
	return a.first<b.first;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int u=0;u<2*m;u++)
	{
		int xtemp,ytemp;
		cin>>xtemp>>ytemp;
		vv.emplace_back(make_pair(xtemp,ytemp));
	}
	sort(vv.begin(),vv.end(),cmp);
	for(int u=0;u<n;u++)
	{
		for(int v=0;v<n;v++)
		{
			long temp;
			cin>>temp;
		}
	}
// 	for(int i=0;i<(int)vv.size();i++)
// 	{
// 		cout<<vv[i].first<<" "<<vv[i].second<<endl;
// 	}
	for(int i=0;i<(int)vv.size();i+=2)
	{
		cout<<(1+abs(vv[i].first-vv[i+1].first)+abs(vv[i].second-vv[i+1].second))<<" ";
		cout<<vv[i].first<<" "<<vv[i].second<<" ";
		int xx=vv[i].first,yy=vv[i].second;
		while(yy!=vv[i+1].second)
		{
			int ttempyy=yy;
			if(vv[i+1].second<vv[i].second)
				yy--;
			else if(vv[i+1].second>vv[i].second)
				yy++;
			if(i>0 && xx==vv[i-1].first && yy==vv[i-1].second)
			{
				yy=ttempyy;
				xx++;
			}

			cout<<xx<<" "<<yy<<" ";
		}
		while(xx!=vv[i+1].first)
		{
			xx++;
			cout<<xx<<" "<<yy<<" ";
		}
		cout<<endl;
	}
return 0;
}