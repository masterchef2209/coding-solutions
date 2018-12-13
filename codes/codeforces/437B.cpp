#include<bits/stdc++.h>
using namespace std;

int main()
{
	int sum,limit;
	cin>>sum>>limit;
	vector<int>bag;
	for(int i=limit;i>0;i--)
	{
		int lowbit =i&(-i);
		if(sum-lowbit<0)
			continue;
		sum-=lowbit;
		bag.push_back(i);
	}
	if(sum>0)
		cout<<-1<<endl;
	else
	{
		cout<<bag.size()<<endl;
		for(int i=0;i<bag.size();i++)
		{
			cout<<bag[i]<<" ";
		}
	}
return 0;
}