#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	pair<int,int> a[n+1];
	for(int i=1;i<=n;i++)
	{
		int z;
		cin>>z;
		a[i]=make_pair(z,i);
	}
	int count=0;
	vector< pair<int,int> > ans;
	for(int p=1;p<=k;p++)
	{
		sort(a+1,a+n+1);
		if(a[n].first-a[1].first<=1)
			break;
		a[n].first--;
		a[1].first++;
		count++;
		ans.push_back(make_pair(a[n].second,a[1].second));
	}
  sort(a+1,a+n+1);
	cout<<a[n].first-a[1].first<<" "<<count<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

return 0;
}