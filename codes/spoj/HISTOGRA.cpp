#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n)
	{
		long long arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		stack<int> s;
		long long maxarea=0;
		long long currarea;
		int tp;
		int i=0;
		while(i<n)
		{
			if(s.empty() || arr[i]>=arr[s.top()])
				s.push(i++);
			else
			{
				tp=s.top();
				s.pop();
				if(s.empty())
					currarea=arr[tp]*i;
				else
					currarea=arr[tp]*(i-s.top()-1);
				if(currarea>maxarea)
					maxarea=currarea;
			}
		}
		while(!s.empty())
		{
			tp=s.top();
			s.pop();
			if(s.empty())
				currarea=arr[tp]*i;
			else
				currarea=arr[tp]*(i-s.top()-1);
			if(currarea>maxarea)
				maxarea=currarea;
		}
		cout<<maxarea<<endl;
	cin>>n;	
	}
return 0;
}