#include<bits/stdc++.h>
using namespace std;
//partially correct
int main()
{
	int n,q,k;
	cin>>n>>q>>k;
  deque<int>que;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			que.push_back(x);
		}
		int ans=0;
		int temp=1;
	while(q--)
	{
		char s;
		cin>>s;
			if(s=='!')
			{
				temp=que.back();
				que.pop_back();
				que.push_front(temp);
			}
			else
			{
				if(temp==1)
				{
					ans=0;
					int count=0;
					for(int i=0;i<que.size();i++)
					{
						if(que[i] == 0)
					{
						if(count>ans)
							ans=count;
						count=0;
					}
					else
					{
						count++;
						if(count>k)
						{
							cout<<k<<endl;
							goto xx;
						}
					}
					if(count>ans)
						ans=count;
					}
				}
				cout<<ans<<endl;
		    xx:;
			}
	}
return 0;
}