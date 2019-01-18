#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		priority_queue<long long>down;
		priority_queue<long long,vector<long long>,greater<long long> >up;
		while(1)
		{
			cin>>n;
			if(n==0)
			{
				break;
			}
			if(n>0)
			{
				if( up.size()>=down.size() )
				{
					if(!up.empty() && n>up.top())
					{
						down.push(up.top());
						up.pop();
						up.push(n);
					}
					else
					{
						down.push(n);
					}
				}
				else
				{
					if(!down.empty() && n<down.top())
					{
						up.push(down.top());
						down.pop();
						down.push(n);
					}
					else
					{
						up.push(n);
					}
				}
			}
			else
			{
				if(!down.empty())
				{
					cout<<down.top()<<endl;
					down.pop();
					if(down.size()<up.size())
					{
						down.push(up.top());
						up.pop();
					}
				}
			}
		}
		cout<<endl;
	}
return 0;
}