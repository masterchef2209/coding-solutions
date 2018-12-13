#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int k1,k2;
	queue<int>q1,q2;
	cin>>k1;
	while(k1--)
	{
		int a;
		cin>>a;
		q1.push(a);
	}
	cin>>k2;
	while(k2--)
	{
		int b;
		cin>>b;
		q2.push(b);
	}
	int turn =0;
	int win=-1;
	for(int i=0;i<10000;i++)
	{
    if(q1.empty() || q2.empty())
      break;
		turn++;
		int a=q1.front();
		q1.pop();
		int b=q2.front();
		q2.pop();
		if(a>b)
		{
			q1.push(b);
			q1.push(a);
			win=1;
		}
		else
		{
			q2.push(a);
			q2.push(b);
			win=2;
		}
	}
  if(turn==10000)
  {
    cout<<-1;
  }
  else
	  cout<<turn<<" "<<win;
return 0;
}