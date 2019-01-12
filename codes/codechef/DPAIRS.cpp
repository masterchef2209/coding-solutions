#include<bits/stdc++.h>
using namespace std;

set<long long> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	pair<long long,int> A[n],B[m];
	for(int i=0;i<n;i++)
	{
		long long temp;
		cin>>temp;
		A[i]=make_pair(temp,i);
	}
	for(int i=0;i<m;i++)
	{
		long long temp;
		cin>>temp;
		B[i]=make_pair(temp,i);
	}
	sort(A,A+n);
	sort(B,B+m);
	for(int j=0;j<m;j++)
		{
			int a=s.size();
			s.insert(A[n-1].first+B[j].first);
			if((int)s.size()!=a)
				cout<<A[n-1].second<<" "<<B[j].second<<endl;
			if((int)s.size()==n+m-1)
			{
				goto label;
			}
		}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a=s.size();
			s.insert(A[i].first+B[j].first);
			if((int)s.size()!=a)
				cout<<A[i].second<<" "<<B[j].second<<endl;
			if((int)s.size()==n+m-1)
			{
				goto label;
			}
		}
	}	
		
	label:;
return 0;
}