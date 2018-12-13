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
		vector< pair<int,char> >vv(2*n);
		for(int i=0;i<2*n;i+=2)
		{
			int a,b;
			cin>>a>>b;
			vv[i]=make_pair(a,'e');
			vv[i+1]=make_pair(b,'l');
		}
		int ans=0,m=INT_MIN;
		sort(vv.begin(),vv.end());
		for(int i=0;i<2*n;i++)
		{
			if(vv[i].second=='e')
			{
				ans++;
				if(ans>m)
				{
					m=ans;
				}
			}
			else if(vv[i].second=='l')
			{
				ans--;
			}
		}
		cout<<m<<endl;
	}
return 0;
}