#include<bits/stdc++.h>
using namespace std;

multiset<long>::iterator it;
multiset<long>::reverse_iterator iit;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	multiset<long>up,down;
	int count=0;
	for(int u=0;u<n;u++)
	{
		int qu;
		cin>>qu;
		if(qu==1)
		{
			count++;
			long x;
			cin>>x;
			if(count<=3)
			{
				down.insert(x);
			}
			else
			{
				it=up.begin();
				if(x> *it)
				{
					long ele=*it;
					up.erase(it);
					down.insert(ele);
					up.insert(x);
				}
				else
				{
					down.insert(x);
				}
			}
			if(count%3==0)
			{
				iit=down.rbegin();
				long ele=*iit;
				down.erase(down.find(ele));
				up.insert(ele);
			}
		}
		else
		{
			if(count<=2)
				cout<<"No reviews yet"<<endl;
			else
				cout<< *up.begin() <<endl;
		}
	}
	return 0;
}