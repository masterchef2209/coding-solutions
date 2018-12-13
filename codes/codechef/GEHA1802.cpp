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
		int n;
		cin>>n;
		int m;
		cin>>m;
		int arr[n+1]={0};
		while(m--)
		{
			int a;
			cin>>a;
			arr[a]++;
		}
    int N=n+1;
    stack<int> ss;
	int area=0;
	int tp;
	int temparea;
	int i=0;
	while(i<N)
	{
		if(ss.empty() || arr[ss.top()]<=arr[i])
			ss.push(i++);
		else
		{
			tp=ss.top();
			ss.pop();
			temparea=arr[tp] * (ss.empty() ? i : i - ss.top() - 1);
			if(area<temparea)
				area=temparea;
		}
	}
	while(ss.empty()==false)
	{
		tp=ss.top();
		ss.pop();
		temparea=arr[tp] * (ss.empty() ? i : i - ss.top() - 1);
		if(area<temparea)
			area=temparea;
	}
		cout<<area<<endl;
	}
return 0;
}