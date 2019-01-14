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
		multiset<long>s;
		vector<long>t,ans;
		int n;
		cin>>n;
		for(int i=0;i<(1<<n);i++)
		{
			long a;
			cin>>a;
			s.insert(a);
		}
		s.erase(0);
		t.push_back(0);
		while(ans.size()<n)
		{
			int s1=*s.begin();
			int ssize=t.size();
			for(int i=0;i<ssize;i++)
			{
				multiset<long>::iterator it=s.find(s1+t[i]);
				long current_sum=*it;
				s.erase(it);
				t.emplace_back(current_sum);
			}
			ans.emplace_back(s1);
		}
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
return 0;
}