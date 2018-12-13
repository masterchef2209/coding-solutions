#include<bits/stdc++.h>
using namespace std;
#define MM 1000000007;

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	vector<long long>v;
	long long count=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			count++;
		}
		else if(s[i]=='b')
		{
			v.push_back(count+1);
			count=0;
		}
	}
	long long ans=1;
	v.push_back(count+1);
	for(int i=0;i<v.size();i++)
	{
		ans=(ans*v[i])%MM;
	}
	cout<<ans-1;
return 0;
}