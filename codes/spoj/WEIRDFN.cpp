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
		priority_queue<long long, vector<long long>, greater<long long> >up;
		priority_queue<long long>down;
		long long a,b,c,n;
		cin>>a>>b>>c>>n;
		long long sum=0;
		long long temp=1;
		for(int i=1;i<=n;i++)
		{
			sum+=temp;
			//cout<<"---"<<temp<<endl;
			if( (up.size())>=(down.size()) )
			{
				if(!up.empty() && temp > up.top())
				{
					down.push(up.top());
					up.pop();
					up.push(temp);
				}
				else
					down.push(temp);
			}
			else
			{
				if(!down.empty() && temp < down.top())
				{
					up.push(down.top());
					down.pop();
					down.push(temp);
				}
				else
					up.push(temp);
			}
			temp= (a%MM * (down.top()%MM )%MM +((b%MM * (i+1)%MM)%MM + c%MM)%MM )%MM;
		}
		cout<<sum<<endl;
	}
return 0;
}