#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	deque<int>dd;
	for(int u=0;u<n;u++)
	{
		int x;
		cin>>x;
		dd.push_back(x);
	}
	int sereja=0,dima=0;
	int i=0;
	while(!dd.empty())
	{
		int num;
		if(dd.front()>dd.back())
		{
			num=dd.front();
			dd.pop_front();
		}
		else
		{
			num=dd.back();
			dd.pop_back();
		}
		if(i&1)
		{
			dima+=num;
		}
		else
		{
			sereja+=num;
		}
	i++;
	}
	cout<<sereja<<" "<<dima;
return 0;
}