#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,v;
	cin>>n>>v;
	int ans=0;
	if(n-1<=v)
		ans=n-1;
	else
	{
		int n1=n-v-1;
		ans+=v;
		int k=2;
		while(n1--)
		{
			ans+=k;
			k++;
		}
	}
	cout<<ans<<endl;
return 0;
}