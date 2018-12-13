#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x;
		cin>>x;
		char c;
		cin>>c;
		int ans=0;
		while(n--)
		{
      char p1,p2,p3,p4,p5;
			cin>>p1>>p2>>p3>>p4>>p5;
			if(x<=0)
			{
				if(p3==c || p5==c)
					ans++;
			}
		x--;
		}
		cout<<ans<<endl;
	}
return 0;
}