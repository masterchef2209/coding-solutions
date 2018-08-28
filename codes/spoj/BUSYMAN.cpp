#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second < b.second)
        return true;
    if(a.second == b.second)
        return (a.first < b.first);
    return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector< pair< int , int > >v(n);
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			v[i].first=a;
     	 	v[i].second=b;
		}
		sort(v.begin(),v.end(),compare);
		int ans=1;
		int x=v[0].second;
		for(int i=1;i<n;i++)
		{
			if(x<=v[i].first)
			{
				ans++;
				x=v[i].second;
			}
		}	
		cout<< ans <<endl;
	}
return 0;
}