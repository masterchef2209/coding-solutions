#include<bits/stdc++.h>
using namespace std;
#define MM 1000000007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		multiset<long long>up,down;
		for(int i=0;i<n;i++)
		{
			long long temp;
			cin>>temp;
			if(up.size()<k)
			{
				up.insert(temp);
			}
			else
			{
				if(temp> *up.begin() )
				{
					auto it=up.begin();
					down.insert(*it);
					up.erase(it);
					up.insert(temp);
				}
				else
				{
					down.insert(temp);
				}
			}
			if(up.size()<k)
				cout<<-1<<" ";
			else
				cout<< *up.begin() <<" ";
		}
		cout<<endl;
	}
return 0;
}